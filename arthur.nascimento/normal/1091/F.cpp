#include <bits/stdc++.h>
#define maxn 100100
#define ll long long
#define debug
using namespace std;

char type[maxn];
ll len[maxn];

ll acc[maxn];

ll has[maxn];
double fly[maxn];

int main(){

    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
        scanf("%lld",len+i);
        
    scanf(" %s",type);
    
    int last = -1;
    ll stamina = 0;
    
    for(int i=0;i<n;i++){
        if(type[i] == 'L'){
            stamina -= len[i];
            if(stamina < 0){
                acc[i] = -stamina;
                stamina = 0;
                last = i;
            }
        }
        else
            stamina += len[i];
    }
    
    stamina = 0;
    for(int i=last+1;i<n;i++){
        has[i] = stamina;
        if(type[i] == 'L')
            stamina -= len[i];
        else
            stamina += len[i];
    }
    
    debug("last %d\n",last);
    ll need = 0;
    for(int i=n-1;i>last;i--){
        if(type[i] == 'L')
            need += len[i];
        else if(type[i] == 'W')
            need -= len[i];
        else if(has[i] - len[i] >= need){
            fly[i] = len[i];
            need += len[i];
        }
        else {
            // has + len - x - x = need => x = (has+len-need)/2 
            fly[i] = 0.5 * (has[i]+len[i]-need);
            break;
        }
        if(need < 0)
            need = 0;
    }
    
    stamina = 0;
    for(int i=last+1;i<n;i++){
        has[i] = stamina;
        if(type[i] == 'L')
            stamina -= len[i];
        else if(type[i] == 'W')
            stamina += len[i];
        else
            stamina += len[i] - 2 * fly[i];
    }
    
    need = 0;
    for(int i=n-1;i>last;i--){
        if(type[i] == 'L')
            need += len[i];
        else if(type[i] == 'G')
            need -= len[i] - 2 * fly[i];
        else if(has[i] - len[i] >= need){
            fly[i] = len[i];
            need += len[i];
        }
        else {
            fly[i] = 0.5 * (has[i]+len[i]-need);
            break;
        }
        if(need < 0)
            need = 0;
    }
    
    ll ans = 0;
    int water = 0;
    for(int i=0;i<n;i++){
        debug("%d fly %.2lf acc %lld\n",i,fly[i],acc[i]);
        if(type[i] == 'L')
            ans += len[i];
        if(type[i] == 'W')
            ans += fly[i] + 3 * (len[i]-fly[i]);
        if(type[i] == 'G')
            ans += fly[i] + 5 * (len[i]-fly[i]);
        if(water)
            ans += 3 * acc[i];
        else
            ans += 5 * acc[i];
        if(type[i] == 'W')
            water = 1;
    }

    printf("%lld\n",ans);

}
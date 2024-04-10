#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define ll long long
#define debug 
#define pii pair<int,int>
using namespace std;
#define sq 100

int pos,val;
void ask(vector<int> v){
    printf("?");
    for(int i=0;i<v.size();i++)
        printf(" %d",v[i]+1);
    printf("\n"); fflush(stdout);
    scanf("%d%d",&pos,&val);pos--;
}

main(){
    
    int k,n;
    scanf("%d%d",&n,&k);
    
    vector<int> v;
    for(int i=0;i<k;i++){
        v.pb(i);
    }
    ask(v);
    int A = pos, x = val;
    
    v.clear();
    for(int i=0;i<=k;i++)
        if(A != i)
            v.pb(i);
            
    ask(v);
    
    int B = pos, y = val;
    
    int ans = 1;
    
    for(int i=0;i<=k;i++)
        if(i != A && i != B){
            
            v.clear();
            for(int j=0;j<=k;j++)
                if(j != i)
                    v.pb(j);
            
            ask(v);
            if(val == y){
                if(x < y) ans++;
            }
            else {
                if(x > y) ans++;
            }
            
        }
        
    printf("! %d\n",ans);
    fflush(stdout);
    
}
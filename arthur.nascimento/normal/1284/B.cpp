#include <bits/stdc++.h>
#define maxn 1001000
#define pb insert
#define ll long long
#define debug 
#define pii pair<int,int>
using namespace std;
 
int mx[maxn];
int mn[maxn];

int qtd[maxn];
 
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int t;
        mn[i] = 1e9;
        mx[i] = -1;
        scanf("%d",&t);
        while(t--){
            int u;
            scanf("%d",&u);
            if(u > mn[i]) mx[i] = maxn-5;
            mx[i] = max(mx[i],u);
            
            mn[i] = min(mn[i],u);
        }
        qtd[mx[i]]++;
    }
    
  //  sort(mx,mx+n);
    for(int i=maxn-2;i>=0;i--)
        qtd[i] += qtd[i+1];
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(mx[i] > maxn-10) ans += n;
        else ans += qtd[1+mn[i]];
    //    printf("ans %lld mn %d\n",ans,mn[i]);
    }
    printf("%lld\n",ans);
    
}
#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug(args...) //printf(args)
using namespace std;

ll f[maxn];
int v[maxn];
ll exp(ll a,ll b,ll m){
    if(b == 0) return 1;
    ll k = exp(a,b/2,m);
    k = (k*k) % m;
    if(b&1) k = (k*a) % m;
    return k;
}

ll qtd[maxn];

main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",v+i);
    sort(v,v+n);
    for(int i=0;i<n;i++){
        int a = v[i];
        a %= m;
        for(int j=0;j<=a;j++)
            qtd[a-j]+=f[j];
        for(int j=a+1;j<m;j++)
            qtd[a-j+m]+=f[j];
        f[a]++;
    }
    
    ll ans = 1;
    for(int i=0;i<m;i++)
        {
            
            ans *= exp(i,qtd[i],m);
            ans %= m;
        }
        
    printf("%lld\n",ans);
}
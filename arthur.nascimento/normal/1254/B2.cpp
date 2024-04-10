#include <bits/stdc++.h>
#define maxn 1001000
#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define debug 
#define mk make_pair
#define pii pair<int,int>
using namespace std;

int v[maxn];

ll aux[maxn];

ll go(ll p,int n){
 
    debug("p %lld\n",p);
    
    for(int i=0;i<n;i++)
        aux[i] = v[i];
    
    ll ans = 0;
    
    ll back = 0, to = 0;
    
    for(int i=0;i<n;i++){
        if(back){
            ll qtd = min(back,aux[i]);
            ans += qtd * (i-to);
            aux[i] -= qtd;
            back -= qtd;
        }
        aux[i] %= p;
        if(2*aux[i] >= p){
            back = p-aux[i];
            to = i;
        }
        else {
            ans += aux[i];
            aux[i+1] += aux[i];
        }
    }
    debug("%lld -> %lld\n",p,ans);
    return ans;
    
}

main(){
    
    int n;
    scanf("%d",&n);
    ll s = 0;
    for(int i=0;i<n;i++){
        scanf("%d",v+i);
        s += v[i];
    }
    
    if(s == 1){
        printf("-1\n");
        return 0;
    }
    
    vector<ll> p;
    for(ll i=2;i*i<=s;i++)
        if(s%i == 0){
            while(s%i == 0) s /= i;
            p.pb(i);
        }
    if(s > 1) p.pb(s);
    
    ll ans = 1e18;
    for(int i=0;i<p.size();i++)
        ans = min(ans,go(p[i],n));
    printf("%lld\n",ans);
}
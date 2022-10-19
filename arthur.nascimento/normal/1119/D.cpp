#include <bits/stdc++.h>
#define maxn 300300
#define ll long long
using namespace std;
#define pii pair<ll,ll>
#define pb push_back
ll v[maxn];
ll ans[maxn];

int main() {
    int n,q;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
        scanf("%lld",v+i);
        
    scanf("%d",&q);
    
    vector<pii> Q;
    
    for(int i=0;i<q;i++){
        ll l,r;
        scanf("%lld%lld",&l,&r);
        Q.pb(pii(r-l,i));
    }
    
    sort(Q.begin(), Q.end());
    
    sort(v,v+n);
    
    vector<ll> V;
    
    for(int i=1;i<n;i++) V.pb(v[i]-v[i-1]);
    
    sort(V.begin(), V.end());
    
    int fre = n;
    int pt = 0;
    ll sf = 0;
    
    for(int i=0;i<q;i++){
        ll t = Q[i].first+1, id = Q[i].second;
        while(pt < V.size() && V[pt] <= t){
            fre--;
            sf += V[pt];
            pt++;   
        }
        ans[id] = t * fre + sf;
    }
    for(int i=0;i<q;i++)
        printf("%lld\n",ans[i]);
}
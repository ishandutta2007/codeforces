// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        vector<pll> qs;
        if(n<=64){
            for(ll i = 3;i<n;i++) qs.push_back({i, n});
            ll e = n;
            while(e>1){
                qs.push_back({n, 2});
                e=(e>>1)+(e&1);
            }
        }else if(n<=4096){
            ll sq=3;
            while((sq+1)*(sq+2)<=n) sq++;
            for(ll i = 3;i<n;i++) if(i!=sq) qs.push_back({i, n});
            qs.push_back({n, sq});
            qs.push_back({sq, n});
            ll e = (n/sq+(n%sq?1:0));
            while(e>1){
                qs.push_back({n, 2});
                e=(e>>1)+(e&1);
            }
        }else{
            ll sqb=3;
            while((sqb+1)*(sqb+2)<=n) sqb++;
            ll k = (n/sqb+(n%sqb?1:0));
            ll sqs=3;
            while((sqs+1)*(sqs+2)<=k) sqs++;
            for(ll i = 3;i<n;i++) if(i!=sqb&i!=sqs) qs.push_back({i, n});
            qs.push_back({n, sqb});
            qs.push_back({sqb, n});
            qs.push_back({n, sqs});
            qs.push_back({sqs, n});
            ll e = (k/sqs+(k%sqs?1:0));
            while(e>1){
                qs.push_back({n, 2});
                e=(e>>1)+(e&1);
            }
        }
        cout<<qs.size()<<'\n';
        for(auto i :qs) cout<<i.x<<' '<<i.y<<'\n';
    }
}
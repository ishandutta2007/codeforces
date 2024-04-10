// -- //
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e4+228;
ll a[N];
vector<pair<pair<ll, ll>, ll>> ops;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        ops.clear();
        ll n, s=0;
        cin >> n;
        for(ll i = 1;i<=n;i++){
            cin >> a[i];
            s+=a[i];
        }
        if(s%n){
            cout<<"-1\n";
            continue;
        }
        ll by = s/n;
        for(ll i = 2;i<=n;i++){
            if(a[i]%i){
                ll e = i-(a[i]%i);
                ops.push_back({{1, i}, e});
                a[1]-=e;
                a[i]+=e;
            }
            ops.push_back({{i, 1}, a[i]/i});
            a[1]+=a[i];
            a[i]=0;
        }
        for(ll i = 2;i<=n;i++){
            ops.push_back({{1, i}, by});
        }
        cout<<ops.size()<<'\n';
        for(auto i :ops) cout<<i.x.x<<' ' <<i.x.y<<' ' <<i.y<<'\n';
	}
}
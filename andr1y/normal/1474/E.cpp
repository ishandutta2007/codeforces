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
        vector<ll> p;
        for(ll i = 0;i<n;i++) p.push_back(i);
        vector<pll> ops;
        swap(p[0], p[n-1]);
        ops.push_back({0, n-1});
        bool fs=1;
        ll rg = n-2;
        ll lf = 1;
        ll res=(n-1)*(n-1);
        for(ll i = 2;i<n;i++){
            if(fs){
                swap(p[0], p[rg]);
                res+=rg*rg;
                ops.push_back({rg, 0});
                rg--;
            }else{
                swap(p[lf], p[n-1]);
                res+=(n-1-lf)*(n-1-lf);
                ops.push_back({lf, n-1});
                lf++;
            }
            fs=!fs;
        }
        cout<<res<<'\n';
        for(auto i : p )cout<<i +1<< ' ';cout<<'\n';
        reverse(begin(ops), end(ops));
        cout<<ops.size()<<'\n';
        for(auto i : ops) cout<<i.x+1 << ' ' <<i.y+1<<'\n';
    }
}
// ++ //
#define pll pair<ll, ll>
#define x first
#define y second
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N = 2e5+228;
vector<pair<pll, ll>> edg;
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll l, r;
    cin >> l >> r;
    ll e = (r-l+1);
    ll k = 1, sz=2;
    edg.push_back({{1, 2}, 1});
    for(ll nk = 2;nk<=e;nk<<=1){
        ++sz;
        edg.push_back({{1, sz}, 1});
        for(ll i = 2;i<sz;i++) edg.push_back({{i, sz}, 1<<(i-2)});
        k<<=1;
    }
    if(e!=k){
        ++sz;
        ll kl=2, kr=e;
        edg.push_back({{1, sz}, 1});
        for(ll i = sz-1;i>=2;i--){
            ll per = (1<<(i-2));
            if(kl+per-1<=kr){
                edg.push_back({{i, sz}, kl-1});
                kl=(kl+per);
            }
        }
    }
    if(l!=1){
        edg.push_back({{sz, sz+1}, l-1});
        sz++;
    }
    cout<<"YES\n";
    cout<<sz<<' '<<edg.size()<<'\n';
    for(auto i : edg) cout<<i.x.x<<' '<<i.x.y<<' '<<i.y<<'\n';
}
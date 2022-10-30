#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 5e5+20;

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, a, b;
        cin >> n>> a >> b;
        vector<ll> x(n);
        copy_n(istream_iterator<ll>(cin), n, x.begin());
        ll res = inf, tx=0, last=0;
        ll pfsum = accumulate(x.begin(), x.end(), 0ll);
        __int128 r = pfsum * b;
        if(r<res)res=r;
        for(ll i = 0;i<n;i++){
            tx += (a+b)*(x[i]-last);
            pfsum -= (n-i)*(x[i]-last);
            r = pfsum * b + tx;
            if(r < res) res=r;
            last=x[i];
        }
        cout<<res<<'\n';
    }
}
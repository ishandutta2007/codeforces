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
const ll N = 2e5+20;

ll fwt[N];
void fwinc(ll p, ll d){
    p++;
    for(;p<N;p+=p&-p) fwt[p]+=d;
}
ll fwget(ll r, ll s=0){
    ++r;
    for(;r;r-=r&-r) s+=fwt[r];
    return s;
}

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        vector<ll> a(n), res(n,0);
        copy_n(istream_iterator<ll>(cin), n, a.begin());
        for(ll i = 0;i<n;i++){
            fwinc(i, a[i]);
            fwinc(i+1, -a[i]);
        }
        ll ones = accumulate(a.begin(), a.end(), 0ll)/n;
        for(ll i = n-1;i>=0;i--){
            ll v = fwget(i);
            bool is1 = ((v>1) || (v && i == 0));
            if(is1) res[i] = 1;
            fwinc(i-ones+1, -1);
            fwinc(i+1, 1);
            if(is1) ones--;
        }
        for(ll i = 0;i<n;i++){
            ll x = fwget(i);
            fwinc(i, -x);
            fwinc(i+1, x);
        }
        assert(ones==0);
        for(auto i : res) cout<<i<<' ';
        cout<<'\n';
    }
}
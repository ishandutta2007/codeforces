#pragma GCC optimize("Ofast")
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

ll smb(ll n){
    if(n==1) return 1;
    if(n%3==0) return 3;
    for(ll i = 5;i*i<=n;i+=6){
        if(n%i==0) return i;
        if(n%(i+2)==0) return i+2;
    }
    return n;
}

bool check(ll n, ll k){
    if(k==1) return false;
    __int128 x = k, in1 = n, ik = k;
    x*=(k+1);
    x/=2;
    if(x <= in1 && (in1-x)%ik==0) return true;
    return false;
}

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        ll mb = __builtin_ctzll(n);
        ll k1 = (1LL<<(mb+1));
        if(check(n, k1)){ cout<<k1<<'\n';continue;}
        ll k2 = smb(n>>mb);
        if(check(n, k2)) cout<<k2<<'\n';
        else cout<<-1<<'\n';
    }
}
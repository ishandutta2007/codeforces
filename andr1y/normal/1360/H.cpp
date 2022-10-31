//password1488
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> yree;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        ll mx = 1ll<<m;
        ll mid = (1LL<<(m-1))-1;
        yree sk;
        for(ll i=mid;i>=mid-120&&i>=0;i--) sk.insert(i);
        for(ll i=mid;i<=mid+120&&i<mx;i++) sk.insert(i);
        ll bf = *(sk.find_by_order(0));
        ll af = mx-*(sk.find_by_order(sk.size()-1))-1;
        ll lf = bf, rf=*(sk.find_by_order(sk.size()-1));
        for(ll i = 0;i<n;i++){
            string s;
            cin >> s;
            ll num=0;
            for(ll j=0;j<m;j++){
                num|=1ll*(s[j]-'0')*(1ll<<(m-j-1));
            }
            if(num<lf) bf--;
            else if(num>rf) af--;
            else{
                sk.erase(num);
            }
        }
        ll ns = (mx-n-1)>>1;
        ns-=bf;
        ll rr = *(sk.find_by_order(ns));
        string ss="";
        for(ll i=0;i<m;i++){
            ss+=(rr&1)+'0';
            rr>>=1;
        }
        reverse(begin(ss), end(ss));
        cout << ss << '\n';
    }
}
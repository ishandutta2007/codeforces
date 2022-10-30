// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5+228;
const ll inf = 0x3fff3fff3fff3fff;
ll a[N], b[N], c[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n1, n2, n3;
    cin >> n1 >> n2>> n3;
    ll sa=0, sb=0, sc=0, ma=inf, mb=inf, mc=inf;
    for(ll i =0;i<n1;i++) {cin >> a[i];sa+=a[i];ma=min(ma, a[i]);}
    for(ll i =0;i<n2;i++) {cin >> b[i];sb+=b[i];mb=min(mb, b[i]);}
    for(ll i =0;i<n3;i++) {cin >> c[i];sc+=c[i];mc=min(mc, c[i]);}
    sort(a, a+n1);
    sort(b, b+n2);
    sort(c, c+n3);
    ll rs = sa+sb+sc-2*min({sa, sb, sc});
    rs=max(rs, sa+sb+sc-2*(ma+mb+mc-max({ma, mb, mc})));
    cout<<rs;
}
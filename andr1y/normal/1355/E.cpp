//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll n, a, r, m;
ll ss[N];
ll cnt(ll t){
    ll ap =0, ar=0;
    for(ll i =0;i<n;i++){
        if(ss[i]>=t) ar+=ss[i]-t;
        if(ss[i]<t)  ap+=t-ss[i];
    }
    ll u = min(m, a+r);
    ll v = u*min(ap, ar)+(ap>ar?(ap-ar)*a:(ar-ap)*r);
    return v;
}
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	cin >> n >> a >> r >> m;
	for(ll i =0;i<n;i++) cin >> ss[i];
    ll l = 0, r = 1000000001;
    while(r-l>2){
        ll m1 = l+(r-l)/3;
        ll m2 = r-(r-l)/3;
        ll v1 = cnt(m1);
        ll v2 = cnt(m2);
        if(v1 >= v2) l=m1;
        if(v1 <= v2) r=m2;
    }
    ll mv = LLONG_MAX;
    for(ll i = l;i<=r;i++) mv=min(mv, cnt(i));
    cout << mv << '\n';
}
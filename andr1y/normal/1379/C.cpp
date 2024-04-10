// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+1488;
pll a[N];
ll sa[N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll m, n;
        cin >> m >> n;
        for(ll i = 0;i<n;i++){
            cin >> a[i].x >> a[i].y;
        }
        sort(a, a+n, greater<pll>());
        sa[0]=a[0].x;
        for(ll i = 1;i<n;i++) sa[i]=sa[i-1]+a[i].x;
        sa[n]=sa[n-1];
        ll mr=0;
        for(ll i = 0;i<n;i++){
            ll l =-1, r=n;
            while(r-l>1){
                ll md = (l+r)>>1;
                if(a[md].x>=a[i].y) l=md;
                else r=md;
            }
            ll tpk = min(l+1+(l<i?1:0), m), tor = tpk;
            ll pr = a[i].x; tpk--;
            if(tpk-1<i){
                pr+=sa[tpk-1];
            }else{
                pr+=sa[tpk]-a[i].x;
            }
            pr+=a[i].y*(m-tor);

            mr=max(mr, pr);
        }
        cout<<mr<<'\n';
    }
}
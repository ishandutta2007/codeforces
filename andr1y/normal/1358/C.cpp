//password1488
#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const ll N = 2e5+228;
inline ll sum1n(ll n) __attribute((always_inline));
inline ll sum1n(ll n){
    return (n*(n+1))>>1;
}
inline ll suka(ll n){
    return (n*(n*n+5))/6;
}
inline ll s2(ll n){
    return (n*(n+1)*(n+2))/6;
}
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int q;
    cin >> q;
    while(q--){
        int or1, oc1, or2, oc2;
        cin >> or1 >> oc1 >> or2 >> oc2;
        ll r1=or1, r2=or2, c1=oc1, c2=oc2;
        ll v1 = sum1n(c1+r1-2)+r1;
        ll v2 = sum1n(c2+r2-2)+r2;
        ll vr1c2 = sum1n(c2+r1-2)+r1;
        ll vr2c1 = sum1n(c1+r2-2)+r2;
//        ll m1 = sum1n(hst1+c2-c1-1)-sum1n(hst1-1)+sum1n(hst1+c2-c1+1+r2-r1-1)-sum1n(hst1+c2-c1)+v1*(c2-c1)+vr1c2*(r2-r1+1);
//        ll m2 = sum1n(hst1+1+r2-r1-1)-sum1n(hst1)+sum1n(hst1+r2-r1+c2-c1-1)-sum1n(hst1+r2-r1-1)+v1*(r2-r1)+vr2c1*(c2-c1+1);
        ll hrz1 = (c2-c1+1)*(r1-1)+suka(r1-1+c2)-suka(r1-1+c1-1);
        ll vrtr1c2 = s2(c2-1+r2)-s2(c2-1+r1-1)-(r2-r1+1)*(c2-1);
        ll path1 = hrz1+vrtr1c2-vr1c2;
        ll hrz2 = (c2-c1+1)*(r2-1)+suka(r2-1+c2)-suka(r2-1+c1-1);
        ll vrt1 = s2(c1-1+r2)-s2(c1-1+r1-1)-(r2-r1+1)*(c1-1);
        ll path2 = hrz2+vrt1-vr2c1;
        ll ot = path2-path1+1;
        long long ot2 = ot;
        cout<<ot2<<'\n';
    }
}
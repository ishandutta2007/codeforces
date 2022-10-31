// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+228;
const ll inf = 0x3fff3fff3fff3fff;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        ll sq=0, rs;
        while((sq*(sq+1))<x+x) sq++;
        ll sum = (sq*(sq+1))>>1;
        ll diff = sum-x;
        if(diff>=2&&diff<=sq+1) diff=0;
        rs=sq+diff;
        cout<<rs<<'\n';
    }
}
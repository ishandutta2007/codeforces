// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
const ll C = 333;
ll a[N];
int e[N][C];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, q, p, k;
    cin >> n;
    for(ll i = 1;i<=n;i++) cin >> a[i];
    for(ll i = n;i;i--){
        for(ll j = 1;j<C;j++){
            e[i][j]=1;
            if(i+a[i]+j<=n) e[i][j]=e[i+a[i]+j][j]+1;
        }
    }
    cin >> q;
    while(q--){
        cin >> p >> k;
        if(k>=C){
            ll r = 0;
            while(p<=n){
                r++;
                p=p+a[p]+k;
            }
            cout<<r<<'\n';
        }else cout<<e[p][k]<<'\n';
    }
}
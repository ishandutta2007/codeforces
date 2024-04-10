// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 101;
ll a[N][N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        memset(a, 0, sizeof(a));
        ll n;
        cin >> n;
        for(ll i = 1;i<n;i+=2){
            a[i][i] = 1;
            a[i-1][i] = 1;
            a[i][i-1]=1;
            a[i-1][i-1]=1;
        }
        if(n&1){
            a[n-1][n-1]=1;
            a[n-1][n-2]=1;
            a[n-2][n-1]=1;
        }
        for(ll i = 0;i<n;i++){
            for(ll j =0;j<n;j++) cout<<a[i][j]<<' ';
            cout<<'\n';
        }
    }
}
// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 120;
char a[N][N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i =0;i<n;i++){
        for(ll j = 0;j<n;j++){
            cin >> a[i][j];
        }
    }
    bool ok =1;
    for(ll i =0;i<n;i++){
        for(ll j = 0;j<n;j++){
            ll e = (i&&a[i-1][j]=='o'?1:0)+(j&&a[i][j-1]=='o'?1:0)+(i+1<n&&a[i+1][j]=='o'?1:0)+(j+1<n&&a[i][j+1]=='o'?1:0);
            if(e&1) ok=0;
        }
    }
    if(ok)cout<<"YES\n";
    else cout<<"NO\n";
}
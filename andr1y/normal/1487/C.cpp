// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 120;
int res[N][N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        memset(res, 0, sizeof(res));
        ll wins = (n-1)/2;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<wins;j++){
                res[i][(i+j+1)%n]=1;
                res[(i+j+1)%n][i]=-1;
            }
        }
        for(ll i = 0;i<n;i++){
            for(ll j = i+1;j<n;j++) cout<<res[i][j]<<' ';
        }
        cout<<'\n';
    }
}
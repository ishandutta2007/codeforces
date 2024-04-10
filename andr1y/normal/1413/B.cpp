// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 512;
ll row[N][N];
ll col[N][N];
ll rp[N*N];
ll rwp[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                cin >> row[i][j];
                rp[row[i][j]] = i;
            }
        }
        for(ll j =0;j<m;j++){
            for(ll i = 0;i<n;i++){
                cin >> col[j][i];
                if(j==0){
                    rwp[i] = rp[col[j][i]];
                }
            }
        }
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                cout<<row[rwp[i]][j]<<' ';
            }
            cout<<'\n';
        }
    }
}
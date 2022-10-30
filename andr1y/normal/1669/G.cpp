#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 53;
char a[N][N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                cin >> a[i][j];
            }
        }
        for(ll j = 0;j<m;j++){
            ll last_f = n-1;
            for(ll i = n-1;i>=0;i--){
                if(a[i][j] == 'o') last_f = i-1;
                else if(a[i][j] == '*'){
                    a[i][j] = '.';
                    a[last_f][j] = '*';
                    last_f--;
                }
            }
        }
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++) cout<<a[i][j];
            cout<<'\n';
        }
    }
}
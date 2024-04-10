// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 101;
ll a[N][N];
bool b[N][N], c[N][N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        vector<pair<ll, pll>> ec;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                cin >> a[i][j];
                b[i][j]=0;
                c[i][j]=0;
                ec.push_back({a[i][j], {i, j}});
            }
        }
        sort(ec.begin(), ec.end());
        for(ll i = 0;i<m;i++) b[ec[i].y.x][ec[i].y.y]=1;
        ll off=0;
        for(ll i = 0;i<n;i++){
            vector<ll> e;
            for(ll j = 0;j<m&&e.size()<off;j++) if(b[i][j]==0) e.push_back(a[i][j]), c[i][j]=1;;
            for(ll j = 0;j<m;j++) if(b[i][j]) off++, e.push_back(a[i][j]), c[i][j]=1;
            for(ll j = 0;j<m;j++){
                if(!c[i][j]) e.push_back(a[i][j]);
            }
            for(auto j: e) cout<<j<<' ';
            cout<<'\n';
        }
    }
}
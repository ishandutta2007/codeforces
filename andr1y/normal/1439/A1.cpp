// -- //
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 101;
char a[N][N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(ll i =0;i<n;i++){
            for(ll j =0;j<m;j++) cin >> a[i][j];
        }
        vector<pair<pair<ll, ll>, pair<pair<ll, ll>, pair<ll, ll>>>> ops;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                if(a[i][j]=='0') continue;
                if(i+1<n&&j+1<m){
                    ops.push_back({ {i, j}, { {i+1, j}, {i, j+1} }});
                    ops.push_back({ {i, j}, { {i+1, j}, {i+1, j+1} }});
                    ops.push_back({ {i, j}, { {i, j+1}, {i+1, j+1} }});
                }else if(i+1==n&&j+1<m){
                    ops.push_back({ {i, j}, { {i-1, j}, {i, j+1} }});
                    ops.push_back({ {i, j}, { {i-1, j}, {i-1, j+1} }});
                    ops.push_back({ {i, j}, { {i, j+1}, {i-1, j+1} }});
                }else if(i+1<n&&j+1==m){
                    ops.push_back({ {i, j}, { {i+1, j}, {i, j-1} }});
                    ops.push_back({ {i, j}, { {i+1, j}, {i+1, j-1} }});
                    ops.push_back({ {i, j}, { {i, j-1}, {i+1, j-1} }});
                }else{
                    ops.push_back({ {i, j}, { {i-1, j}, {i, j-1} }});
                    ops.push_back({ {i, j}, { {i-1, j}, {i-1, j-1} }});
                    ops.push_back({ {i, j}, { {i, j-1}, {i-1, j-1} }});
                }
            }
        }
        cout<<ops.size()<<'\n';
        for(auto i : ops){
            cout<<i.x.x+1<<' '<<i.x.y+1<<' '<<1+i.y.x.x<<' '<<1+i.y.x.y<<' '<<1+i.y.y.x<<' '<<1+i.y.y.y<<'\n';
        }
    }
}
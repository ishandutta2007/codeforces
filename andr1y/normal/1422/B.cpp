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
        ll n, m;
        cin >> n >> m;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++) cin >> a[i][j];
        }
        ll res=0;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                ll v1 = a[i][j];
                ll v2 = a[n-i-1][j];
                ll v3 = a[i][m-j-1];
                ll v4 = a[n-i-1][m-j-1];
                ll vk = min(min(v1, v2), min(v3, v4));
                ll e1 = abs(v1-v1)+abs(v2-v1)+abs(v3-v1)+abs(v4-v1);
                ll e2 = abs(v1-v2)+abs(v2-v2)+abs(v3-v2)+abs(v4-v2);
                ll e3 = abs(v1-v3)+abs(v2-v3)+abs(v3-v3)+abs(v4-v3);
                ll e4 = abs(v1-v4)+abs(v2-v4)+abs(v3-v4)+abs(v4-v4);
                ll ek = min(min(e1, e2), min(e3, e4));
                res+=ek;
            }
        }
        cout<<res/4<<'\n';
    }
}
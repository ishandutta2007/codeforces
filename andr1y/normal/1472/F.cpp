// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
pll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(ll i =0;i<m;i++){
            cin >> a[i].x >> a[i].y;
        }
        sort(a, a+m, [](pll a, pll b){
            return a.y < b.y;
        });
        bool ok =1;
        for(ll i = 0;i<m&&ok;i++){
            ll ban=1;
            if(i+1<m&&a[i+1].y==a[i].y){
                ban++;
                i++;
            }
            if(ban==2) continue;
            if(i+1==m) ok=0;
            ll ban_next=0;
            if(i+1<m) ban_next++;
            if(i+2<m&&a[i+2].y==a[i+1].y) ban_next++;
            if(ban_next==2) ok=0;
            ban_next=a[i+1].x;
            if(((a[i].y&1)==(a[i+1].y&1)&&ban_next==a[i].x) || ((a[i].y&1)!=(a[i+1].y&1)&&ban_next!=a[i].x)) ok=0;
            i++;
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
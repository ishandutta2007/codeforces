// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 128;
#define pll pair<ll, ll>
#define x first
#define y second
pll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, k;
        cin >> n >> k;
        bool ok =1;
        for(ll i = 0;i<n;i++){
            cin >> a[i].x >> a[i].y;
        }
        for(ll i = 0;i<n;i++){
            ok=1;
            for(ll j = 0;j<n&&ok;j++){
                if(i==j) continue;
                ll v = abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
                if(v>k) ok=0;
            }
            if(ok){
                cout<<"1\n";
                break;
            }
        }
        if(!ok) cout<<"-1\n";
    }
}
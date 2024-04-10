// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
pll a[N];
ll deg[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, s=0;
        cin >> n;
        for(ll i = 1;i<=n;i++){
            cin >> a[i].x;
            a[i].y=i;
            deg[i]=0;
            s+=a[i].x;
        }
        for(ll a, b, i = 1;i<n;i++){
            cin >> a >> b;
            deg[a]++, deg[b]++;
        }
        sort(a+1, a+n+1, greater<pll>());
        ll k = 1;
        for(ll i = 1;i<n;i++){
            cout<<s<<' ';
            while(k<=n&&deg[a[k].y]<2) k++;
            s+=a[k].x;
            deg[a[k].y]--;
        }
        cout<<'\n';
    }
}
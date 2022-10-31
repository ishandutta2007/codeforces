// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
pll a[N];
ll y[N];
ll bls[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m, x;
        cin >> n >> m >> x;
        for(ll i = 0;i<n;i++){
            cin >> a[i].x;
            a[i].y=i;
        }
        for(ll i = 0;i<m;i++) bls[i]=0;
        sort(a, a+n);
        for(ll i = 0;i<n;i++){
            bls[i%m]+=a[i].x;
            y[a[i].y]=i%m;
        }
        sort(bls, bls+m);
        if(bls[m-1]-bls[0]<=x){
            cout<<"YES\n";
            for(ll i = 0;i<n;i++) cout<<y[i]+1<<' ';
            cout<<'\n';
        }else cout<<"NO\n";
    }
}
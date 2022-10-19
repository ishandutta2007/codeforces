#include <bits/stdc++.h>
/// 500 485 462 A4
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll vis[N];
int Main(){
    ll a,b;
    cin >> a >> b;
    ll n=a+b;
    for (int i=0;i<=n;i++){
        vis[i]=0;
    }
    ll x=(n+1)/2;
    ll y=n/2;
    for (int i=0;i<=min(b,x);i++){
        if (i+y<b) continue;
        ll z=i+y-b;
        vis[z+i]=1;
    }
    swap(a,b);
    for (int i=0;i<=min(b,x);i++){
        if (i+y<b) continue;
        ll z=i+y-b;
        vis[z+i]=1;
    }
    vector <int> ans;
    for (int i=0;i<=n;i++){
        if (vis[i]) ans.pb(i);
    }
    cout << ans.size() << endl;
    for (auto u : ans) cout << u << " ";
    cout << endl;
    return 0;

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--){
        Main();
    }
}
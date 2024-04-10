#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
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
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++) vis[i]=0;
    ll m;
    cin >> m;
    for (int i=1;i<=m;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        vis[b]=1;
    }
    for (int i=1;i<=n;i++){
        if (vis[i]==0){
            for (int j=1;j<=n;j++){
                if (j==i) continue;
                cout << i << " " << j << endl;
            }
            return 0;
        }
    }
    cout << 1/0;
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}
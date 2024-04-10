#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll ans[N];
ll a[N],b[N],c[N];
ll Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        cin >> b[i];
    }
    for (int i=1;i<=n;i++){
        cin >> c[i];
    }
    ans[0]=-1e9;
    for (int i=1;i<n;i++){
        if (a[i]!=ans[i-1]){
            ans[i]=a[i];
            continue;
        }
        if (b[i]!=ans[i-1]){
            ans[i]=b[i];
            continue;
        }
    }
    if (a[n]!=ans[n-1] && a[n]!=ans[1]) ans[n]=a[n];
    if (b[n]!=ans[n-1] && b[n]!=ans[1]) ans[n]=b[n];
    if (c[n]!=ans[n-1] && c[n]!=ans[1]) ans[n]=c[n];
    for (int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}
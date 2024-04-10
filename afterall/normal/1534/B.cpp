#include <bits/stdc++.h>
/// this time?
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
const int N=4e5+100;
ll a[N];
ll Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    ll ans=0;
    a[n+1]=0;
    for (int i=1;i<=n;i++){
        if (a[i]>a[i+1] && a[i]>a[i-1]){
            ans+=a[i]-(max(a[i-1],a[i+1]));
            a[i]=max(a[i+1],a[i-1]);
        }
    }
    for (int i=1;i<=n;i++){
        if (a[i]>a[i-1]) ans+=a[i]-a[i-1];
        if (a[i]>a[i+1]) ans+=a[i]-a[i+1];
    }
    kill(ans);
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
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
ll a[N];
int Main(){
    ll n;
    cin >> n;
    ll s=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        s+=a[i];
    }
    sort(a+1,a+n+1);
    ll z=s%(n-1);
    if (z!=0) z=n-1-z;
    ll ans=z;
    s+=z;
    if (s/(n-1)<a[n]){
        ans+=a[n]*(n-1)-s;
    }
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}
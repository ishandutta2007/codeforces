#include <bits/stdc++.h>
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
#define kill(x) cout<<x<<'\n';
using namespace std;
void Main(){
    ll n;
    cin >> n;
    ll ans=0;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        ans+=1ll * (i+1)*(n-i)*(x ? 1 : 2);
    }
    cout << ans  << endl;
}
int32_t main(){
    sync;
    int t=1;
    cin >> t;
    while(t--) Main();
}
#include <bits/stdc++.h>
/// 500 485 462 A4
using namespace std;
typedef long long int ll;
typedef complex<long double> point;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=2e5+100;
int Main(){
    ll n;
    cin >> n;
    ld ans=0;
    vector <int> a,b;
    for (int i=1;i<=2*n;i++){
        ll x,y;
        cin >> x >> y;
        if (x==0) a.pb(abs(y));
        else b.pb(abs(x));
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if (a.size()!=b.size()) return 1/0;
    for (int i=0;i<a.size();i++){
        ans+=pow(a[i]*a[i]+b[i]*b[i],0.5);
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}
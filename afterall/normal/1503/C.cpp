/// Black lives matter
#include <bits/stdc++.h>
/// 500 485 462 A4
using namespace std;
typedef long long int ll;
typedef complex<double> point;
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
const int N=2e5+100;
ll mx[N];
int32_t main(){
    sync;
    vector <pair <pii,int> > a;
    ll ans=0;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        ll x,y;
        cin >> x >> y;
        a.pb({{x,y},i});
        ans+=y;
    }
    sort(a.begin(),a.end());
    mx[0]=a[0].F.F;
    for (int i=0;i<n;i++){
        if (mx[i]<a[i].F.F) ans+=a[i].F.F-mx[i];
        mx[i+1]=max(mx[i],a[i].F.F+a[i].F.S);
    }
    cout << ans << endl;

}
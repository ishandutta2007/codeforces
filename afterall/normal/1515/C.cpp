#include <bits/stdc++.h>
/// 500 485 462 A4
/// yani mishe?
using namespace std;
typedef long long int ll;
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
ll ans[N];
ll a[N];
int Main(){
    ll n,m,x;
    cin >> n >> m >> x;
    for (int i=1;i<=n;i++) cin >> a[i];
    set <pii> s;
    for (int i=1;i<=m;i++) s.insert({0,i});
    for (int i=1;i<=n;i++){
        pii p=*s.begin();
        s.erase(p);
        ans[i]=p.S;
        p.F+=a[i];
        s.insert(p);
    }
    cout << "YES" << endl;
    for (int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) {
        Main();
    }
}
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

int Main(){
    ll a,b,c;
    cin >> a >> b >> c;
    ll ans=0;
    if (a) ans++,a--;
    if (b) ans++,b--;
    if (c) ans++,c--;
    vector <int> d;
    d.pb(a);
    d.pb(b);
    d.pb(c);
    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());
    a=d[0],b=d[1],c=d[2];
    d.clear();
    if (a && b) ans++,a--,b--;
    if (a && c) ans++,a--,c--;
    if (b && c) ans++,b--,c--;
    if (a && b && c) ans++;
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}
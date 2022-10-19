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
    ll x,y;
    cin >> x >> y;
    if (x<0) x=-x;
    if (y<0) y=-y;
    ll ans=2*(min(x,y));
    if (x!=y)
        ans+=2*(max(x,y)-min(x,y))-1;
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}
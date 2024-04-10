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
ll t[N][2];
int Main(){
    ll n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    s='.'+s;
    for (int i=1;i<=n;i++){
        t[i][0]=t[i-1][0];
        t[i][1]=t[i-1][1];
        t[i][s[i]-'0']++;
    }
    while(q--){
        ll l,r;
        cin >> l >> r;
        ll p1=0;
        if (t[l-1][s[l]-'0'])p1=1;
        if (t[n][s[r]-'0']-t[r][s[r]-'0']) p1=1;
        if (p1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}
#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) cout << x << endl;return ;
using namespace std;
const int N=2e5+100;
void Main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;
    vector <int> a,b;
    if (s[0]!=t[0]){
        cout << -1 << endl;
        return;
    }
    for (int i=1;i<n;i++){
        if (s[i]!=s[i-1]) a.pb(i);
        if (t[i]!=t[i-1]) b.pb(i);
    }
    if (a.size()!=b.size()){
        cout << -1 << endl;
        return;
    }
    ll ans=0;
    for (int i=0;i<a.size();i++) ans+=abs(a[i]-b[i]);
        cout << ans << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while (t--) Main();
}
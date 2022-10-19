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
#define kill(x) cout << x << endl;return;
using namespace std;
const int N=2e5+100;

void Main(){
    ll n;
    cin >> n;
    ll p1=0;
    vector <int> a;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        a.pb(x);
        if (x==1) p1=1;
    }
    if (!p1) {
        cout << "YES" << endl;return;
    }
    sort(a.begin(),a.end());
    for (int i=1;i<n;i++){
        if (a[i]-a[i-1]==1) {
            cout << "NO" << endl;return;
        }
    }
    cout << "YES" << endl;return;

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}
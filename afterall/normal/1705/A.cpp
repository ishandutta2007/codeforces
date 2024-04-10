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
    cin >> n ;
    n*=2;
    ll x;
    cin >> x;
    vector <int> a;
    for (int i=0;i<n;i++) {
        ll z;
        cin >> z;
        a.pb(z);
    }
    sort(a.begin(),a.end());
    for (int i=0;i<n/2;i++) {
        if (a[i]+x>a[i+n/2]){
            cout << "NO" << endl;return;
        }
    }
    cout << "YES" << endl;

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while (t--) Main();
}
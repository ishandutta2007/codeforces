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
ll a[N];
void Main(){
    ll n;
    cin >> n ;
    vector <pii> a;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        a.pb({x,i+1});
    }
    if (n==1){
        cout << 1 << " " << 1 << endl;
        return ;
    }
    sort(a.begin(),a.end());
    cout << a[0].S << " " << a.back().S << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}
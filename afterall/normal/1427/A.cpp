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
    ll n;
    cin >> n;
    vector <int> a;
    ll s=0;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        a.pb(x);
        s+=x;
    }
    if (s==0) kill("NO");
    sort(a.begin(),a.end());
    cout << "YES" << endl;
    if (s<0){
        for (auto u : a) cout << u << " ";
        cout << endl;
    }
    else{
        reverse(a.begin(),a.end());
        for (auto u : a) cout << u << " ";
        cout << endl;
    }
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--){
        Main();
    }
}
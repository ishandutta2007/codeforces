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
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        a.pb(x);
    }
    sort(a.begin(),a.end());
    for (int i=1;i<a.size();i++){
        if (a[i]==a[i-1]) kill("YES");
    }
    kill("NO");
}
int32_t main(){
    ll t;
    t=1;
    cin >> t;
    while(t--) Main();
}
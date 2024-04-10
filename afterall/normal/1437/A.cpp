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

int32_t main(){
    ll t;
    cin >> t;
    while(t--){
        ll l,r;
        cin >> l >> r;
        if (2*l>r) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
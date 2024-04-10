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
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;

int Main(){
    ll n;
    cin >> n;
    vector <int> a,b;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        a.pb(x);
    }
    sort(a.begin(),a.end());
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        b.pb(x);
    }
    sort(b.begin(),b.end());
    for (int i=0;i<n;i++){
        if (a.back()>b.back()) kill("NO");
        if (b.back()-1<=a.back()){
            a.pop_back();
            b.pop_back();
        }
        else kill("NO");
    }
    kill("YES");
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}
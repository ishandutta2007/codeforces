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
    string s;
    cin >> s;
    ll ans=0;
    ll t1=0,t2=0;
    for (int i=0;i<s.size();i++){
        if (s[i]=='(') t1++;
        if (s[i]==')'){
            if (t1) t1--,ans++;
        }
        if (s[i]=='['){
            t2++;
        }
        if (s[i]==']'){
            if (t2) t2--,ans++;
        }
    }
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}
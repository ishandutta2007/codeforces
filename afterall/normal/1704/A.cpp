#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define int long long
#define endl '\n'
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) cout << x << endl;return ;
using namespace std;
const int N=2e5+100;

void Main(){
    string s,t;
    ll n,m;
    cin >> n >> m;
    cin >> s >> t;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    if (t.size()>s.size()){
        cout << "NO" << endl;
        return;
    }
    for (int i=0;i<(ll)t.size()-1;i++){
        if (s[i]!=t[i]){
            cout << "NO" << endl;
            return;
        }
    }
    for (int i=(ll)t.size()-1;i<s.size();i++){
        if (t[t.size()-1]==s[i]){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}
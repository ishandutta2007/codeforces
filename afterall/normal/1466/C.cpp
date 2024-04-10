#include <bits/stdc++.h>
/// 500 485
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll dp[N];
int Main(){
    string s;
    cin >> s;
    ll n=s.size();
    s='.'+s;
    ll ans=0;
    for (int i=n;i;i--){
        if (s[i]=='.') continue;
        if (i-1>0){
            if (s[i]==s[i-1]){
                ans++;
                s[i-1]='.';
            }
        }
        if (i-2>0){
            if (s[i]==s[i-2]){
                s[i-2]='.';
                ans++;
            }
        }

    }
    cout << ans << endl;

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while (t--) Main();
}
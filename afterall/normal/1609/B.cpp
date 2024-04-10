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

const int N=2e5+100;
string s;
ll n,q;
ll check(ll x){
    if (x+2>=n || x<0) return 0;
    if (s[x]=='a' && s[x+1]=='b' && s[x+2]=='c') return 1;
    return 0;
}
ll Main(){
    cin >> n >> q;
    cin >> s;
    ll ans=0;
    for (int i=0;i<n;i++) ans+=check(i);
    for (int i=1;i<=q;i++){
       // cout << i << " ejrn " << q << endl;
        ll x;
        cin >> x;
        x--;
        char c;
        cin >> c;
        for (int j=x-5;j<=x+5;j++) ans-=check(j);
        s[x]=c;
        for (int j=x-5;j<=x+5;j++) ans+=check(j);
        cout << ans << endl;
    }
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
   // cin >> t;
    while(t--){
        Main();
    }
}
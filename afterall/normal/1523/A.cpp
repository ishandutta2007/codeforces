#include <bits/stdc++.h>
/// this time?
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e3;
ll vis[N];
int Main(){
    ll n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    m=min(m,n);
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++) vis[j]=0;
        for (int j=0;j<n;j++){
            if (s[j]=='1') continue;
            if (j<n-1 && s[j+1]=='1') vis[j]++;
            if (j>0 && s[j-1]=='1') vis[j]++;
        }
        for (int j=0;j<n;j++){
            if (vis[j]==1) s[j]='1';
        }
    }
    kill(s);
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--){
        Main();
    }
}
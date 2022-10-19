#include <bits/stdc++.h>
/// this time?
typedef int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100,M=64,P=16;
vector <int> love[N];
ll W[M];
ll n;
ll val[N];
ll dp[(1<<P)];
ll mx=0;
vector <int> ans;
ll cc=0;
void solve(vector <int> a){
    memset(W,0,sizeof W);
    ll m=a.size();
    for (int i=0;i<m;i++){
        W[a[i]]=i+1;
    }
    cc++;
    memset(dp,0,sizeof dp);
    for (int i=1;i<=n;i++){
        val[i]=0;
        for (auto u : love[i]){
            if (W[u]==0) continue;
            val[i]+=(1<<(W[u]-1));
        }
        dp[val[i]]++;
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<(1<<m);j++){
            if ((j & (1<<i))==0) dp[j]+=dp[j+(1<<i)];
        }
    }
    for (int i=0;i<(1<<m);i++){
        if (dp[i]>=(n+1)/2){
            ll z=__builtin_popcount(i);
            if (z>mx){
                mx=z;
                ans.clear();
                for (int j=0;j<m;j++){
                    if ((i & (1<<j))) ans.pb(a[j]);
                }

            }
        }
    }
}
int32_t main(){
    sync;
    mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    ll m,p;
    cin >> n >> m >> p;
    uniform_int_distribution<> rnd(1,n);
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        for (int j=0;j<s.size();j++){
            if (s[j]=='1'){
                love[i].pb(j+1);
            }
        }
    }
    for (int i=0;i<60;i++){
        ll x=rnd(rng);
     //   cout << x << " ej " << mx << endl;
        vector <int> a;
        a=love[x];
        solve(a);
    }
    string jav="";
    for (int i=0;i<m;i++) jav+='0';
    for (auto u : ans){
        jav[u-1]='1';
    }
    kill(jav);
}
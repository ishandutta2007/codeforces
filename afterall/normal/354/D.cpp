#include <bits/stdc++.h>
typedef int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e5+100,sq=800;
ll dp[2][sq];
vector <int> ja[N];
ll n,q;

int32_t main(){
    memset(dp,31,sizeof dp);
    dp[0][0]=0;
    cin >> n >> q;
    for (int i=1;i<=q;i++){
        ll s,so;
        cin >> s >> so;
        ll x=s-so;
        x=n-x;
        ja[x].pb(s);
    }
    for (int i=1;i<=n;i++){
        sort(ja[i].begin(),ja[i].end());
    }
    for (int i=1;i<=n;i++){
        if (i<sq)
        dp[1][i]=0;
        vector <int> t=ja[i];
        dp[1][0]=dp[1-1][0]+ja[i].size()*3;
        for (int j=1;j<min(i+1,sq);j++){
            if (t.size() && n-t.back()+1==j) t.pop_back();
            dp[1][0]=min((ll)dp[1][0],(ll)dp[1-1][j-1]+(ll)t.size()*3+(ll)j*(j+1)/2+2);
        }
        for (int j=1;j<min(i,sq);j++){
            if (ja[i].size() && n-ja[i].back()+1==j) ja[i].pop_back();
            dp[1][j]=dp[1-1][max((ll)0,j-1)]+ja[i].size()*3;
            dp[1][j]=min(dp[1][j],dp[1][j-1]);
        }
        for (int j=0;j<sq;j++) {
            dp[0][j]=dp[1][j];
            dp[1][j]=1e8;
        }
        //if (i==2) cout << dp[0][0] << endl;
    }
    cout << dp[0][0];
}
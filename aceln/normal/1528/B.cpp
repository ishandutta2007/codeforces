#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const int inf=2e9;
const ll inff=1e18;
const ll mod=998244353;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
//#define int ll

ll dp[maxn];
ll m[maxn];

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
    dp[1]=1;
    ll sum=1;
    for (int i=2;i<=1000000;i++)
        for (int j=i;j<=1000000;j+=i) m[j]++;

    for (int i=2;i<=1000000;i++) {
        dp[i]=(sum+m[i]+1)%mod;
        sum=(sum+dp[i])%mod;
    }
    int n; cin>>n;
    cout<<dp[n]<<'\n';
}
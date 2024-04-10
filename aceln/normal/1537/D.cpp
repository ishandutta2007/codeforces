#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const int inf=2e9;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
//#define int ll

int dp[maxn];

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
    for (int i=1;i<=100;i++) {
        for (int j=2;j<i;j++) {
            if (i%j==0) {
                if (dp[i-j]==0) dp[i]=1;
            }
        }
        //cout<<i<<' '<<dp[i]<<'\n';
        //if (i>=100 && (dp[i] != (i&1^1))) cout<<i << ' '<<"vgwwe\n";
    }
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        if (n<=100) cout<<(dp[n]^1 ? "Bob\n" : "Alice\n");
        else if (__builtin_popcount(n)==1) {
            for (int j=0;j<=30;j++) {
                if ((n>>j)&1) {
                    if (j&1) cout<<"Bob\n";
                    else cout<<"Alice\n";
                }
            }
        }
        else if (n&1) cout<<"Bob\n";
        else cout<<"Alice\n";
    }
}
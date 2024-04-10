#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
void solve() {
        string x;
        cin >> x;
        int n=x.size();
        ll kiedy[2][2];
        rep(i, 2) rep(j, 2) kiedy[i][j]=n;
        ll dp[n], ans=0;
        rep(i, n) dp[i]=n;
        for(ll i=n-1; i>=0; --i) {
                if(x[i]=='1') {
                        dp[i]=min(dp[i], kiedy[1][(i+1)%2]);
                        dp[i]=min(dp[i], kiedy[0][i%2]);
                        kiedy[1][i%2]=i;
                } else if(x[i]=='0') {
                        dp[i]=min(dp[i], kiedy[0][(i+1)%2]);
                        dp[i]=min(dp[i], kiedy[1][i%2]);
                        kiedy[0][i%2]=i;
                }
                if(i<n-1) dp[i]=min(dp[i], dp[i+1]);
                ans+=dp[i]-i;
        }
        cout << ans << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}
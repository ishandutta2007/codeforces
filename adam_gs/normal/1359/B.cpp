#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int t;
        cin >> t;
        while(t--) {
                int n, m, a, b, ans=0;
                cin >> n >> m >> a >> b;
                b=min(2*a, b);
                while(n--) {
                        string x;
                        cin >> x;
                        int dp[m];
                        rep(i, m) dp[i]=0;
                        if(x[0]=='.') dp[0]=a;
                        if(m>=2) if(x[1]=='.') if(x[0]=='.') dp[1]=b; else dp[1]=a; else dp[1]=dp[0];
                        rep(i, m-2) {
                                if(x[i+2]=='.') {
                                        if(x[i+1]=='.') {
                                                dp[i+2]=dp[i]+b;
                                        } else {
                                                dp[i+2]=dp[i+1]+a;
                                        }
                                } else dp[i+2]=dp[i+1];
                        }
                        ans+=dp[m-1];
                }
                cout << ans << '\n';
        }
}
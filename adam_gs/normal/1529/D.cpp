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
const ll MOD=998244353;
const int LIM=1e6+7;
ll dp[LIM];
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n;
        cin >> n;
        for(int i=1; i<=n; ++i) {
                for(int j=2*i; j<=n; j+=i) ++dp[j];
        }
        dp[0]=1;
        ll sum=1;
        for(int i=1; i<=n; ++i) {
                dp[i]=(dp[i]+sum)%MOD;
                sum=(sum+dp[i])%MOD;
        }
        cout << dp[n] << '\n';
}
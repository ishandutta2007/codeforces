#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
const int LIM=1e5+7;
long long val[LIM], dp[LIM];
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n;
        cin >> n;
        rep(i, n) {
                long long a;
                cin >> a;
                val[a]+=a;
        }
        dp[1]=val[1];
        rep(i, LIM-5) dp[i+2]=max(val[i+2]+dp[i], dp[i+1]);
        cout << dp[LIM-5];
}
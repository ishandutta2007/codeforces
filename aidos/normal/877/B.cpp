#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
string s;
int dp[5050][4];
void solve() {
    cin >> s;
    s = "#" + s;
    for(int i = 1; i < s.size(); i++) {
        int sb = s[i] - 'a';
        dp[i][1] = dp[i-1][1] + 1-sb;
        dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + sb;
        dp[i][3] = max(dp[i-1][2], dp[i-1][3]) + 1-sb;
    }
    cout << max(dp[s.size()-1][2], dp[s.size()-1][3]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}
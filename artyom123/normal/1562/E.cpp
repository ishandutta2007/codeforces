 #include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long 
#define mp make_pair

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<vector<int>> lcp(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (s[i] == s[j]) {
                    lcp[i][j] = 1;
                    lcp[i][j] += lcp[i + 1][j + 1];
                }
            }
        }
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = n - i;
            for (int j = i - 1; j >= 0; j--) {
                int x = lcp[i][j];
                if (i + x < n && s[i + x] > s[j + x]) dp[i] = max(dp[i], dp[j] + n - i - x);
            }
        }
        cout << *max_element(all(dp)) << "\n";
    }
    return 0;
}
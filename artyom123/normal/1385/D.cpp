#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

int n;
string s;
vector<vector<int>> gist;
map<pair<int, int>, int> dp;

int get(int l, int r, char c) {
    //cout << l << " " << r << " " << c << "\n";
    if (dp.find({l, r}) != dp.end()) return dp[{l, r}];
    if (l == r) {
        dp[{l, r}] = 1 - (gist[r][c - 'a'] - (l == 0 ? 0 : gist[l - 1][c - 'a']));
        return dp[{l, r}];
    }
    int m = (l + r) / 2;
    dp[{l, r}] = min(get(l, m, c + 1) + (r - m) - (gist[r][c - 'a'] - gist[m][c - 'a']),
                     get(m + 1, r, c + 1) + (m - l + 1) - (gist[m][c - 'a'] - (l == 0 ? 0 : gist[l - 1][c - 'a'])));
    return dp[{l, r}];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        gist.clear();
        gist.assign(n, vector<int>(26));
        gist[0][s[0] - 'a']++;
        dp.clear();
        for (int i = 1; i < n; i++) {
            gist[i] = gist[i - 1];
            gist[i][s[i] - 'a']++;
        }
        cout << get(0, n - 1, 'a') << "\n";
    }
    return 0;
}
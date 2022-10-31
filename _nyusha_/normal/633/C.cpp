#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
unordered_map < ll, string > d;
int const maxn = 10005;
int dp[maxn], where[maxn];
ll p = 29, mod = 1e9 + 7;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    string S, s, to;
    cin >> S;
    S = "#" + S;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> s;
        to = "";
        for (auto c : s) {
            if ('a' <= c && c <= 'z') to += c;
            else to += char('a' + c - 'A');
        }
        ll h = 0;
        for (auto c : to) {
            h = (h * p + c - 'a' + 1) % mod;
        }
        d[h] = s;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        ll h = 0;
        for (int j = i; j >= max(1, i - 1001); --j) {
            h = (h * p + S[j] - 'a' + 1) % mod;
            if (dp[j - 1] && d.find(h) != d.end()) {
                dp[i] = 1;
                where[i] = j - 1;
                break;
            }
        }
    }
    int pos = n;
    vector < string > ans;
    while (pos >= 1) {
        ll h = 0;
        for (int i = pos; i > where[pos]; --i) {
            h = (h * p + S[i] - 'a' + 1) % mod;
        }
        ans.push_back(d[h]);
        pos = where[pos];
    }
    reverse(ans.begin(), ans.end());
    for (auto elem : ans) cout << elem << " ";
    return 0;
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 5005;

int st[MN], k, dp[MN][MN];
vector<int> now, a, b;
string s;

void solve() {
    for (int i = s.size() - 1; i >= 0; i--) {
        dp[i][i + 1] = 1;
        for (int j = i + 2; j <= s.size(); j++) {
            if (s[i] == s[j - 1]) {
                if (j - 4 > i) dp[i][j] = dp[i + 2][j - 2];
                else dp[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j <= s.size(); j++) st[i] += dp[i][j];
        now.push_back(i);
    }
}

int main() {
    boost();

    cin >> s >> k;
    solve();
    string ans = "";
    for (int len = 0; len <= s.size(); len++) {
        a.clear(), b.clear();
        int sum0 = 0, sum1 = 0, sum2 = 0;
        for (int i = 0; i < now.size(); i++) {
            if (dp[now[i]][now[i] + len]) {
                sum0++, st[now[i]]--;
            }
            if (now[i] < s.size() - len) {
                if (s[now[i] + len] == 'a') {
                    sum1 += st[now[i]];
                    a.push_back(now[i]);
                } else {
                    sum2 += st[now[i]];
                    b.push_back(now[i]);
                }
            }
        }
        if (k <= sum0) {
            cout << ans << endl;
            return 0;
        } else k -= sum0;
        if (k <= sum1) {
            ans += 'a';
            now = a;
            continue;
        } else k -= sum1;
        if (k <= sum2) {
            ans += 'b';
            now = b;
            continue;
        }
    }

    return 0;
}
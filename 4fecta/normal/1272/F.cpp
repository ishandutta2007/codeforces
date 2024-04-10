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

struct node {
    int i, j, k;
};

const int MN = 205;

int n, m, dp[MN][MN][MN];
node pre[MN][MN][MN];
char c[MN][MN][MN];
string s, t;

int main() {
    boost();

    memset(dp, -1, sizeof(dp));
    cin >> s >> t;
    n = s.size(), m = t.size();
    s = "$" + s + "$", t = "$" + t + "$";
    queue<node> q;
    dp[1][1][0] = 0;
    pre[1][1][0] = {0, 0, 0};
    q.push({1, 1, 0});
    while (q.size()) {
        node cur = q.front(); q.pop();
        if (cur.k > 0) { //insert ')'
            int i = cur.i + (s[cur.i] == ')'), j = cur.j + (t[cur.j] == ')');
            if (dp[i][j][cur.k - 1] == -1) {
                dp[i][j][cur.k - 1] = dp[cur.i][cur.j][cur.k] + 1;
                pre[i][j][cur.k - 1] = {cur.i, cur.j, cur.k};
                c[i][j][cur.k - 1] = ')';
                q.push({i, j, cur.k - 1});
            }
        }
        if (cur.k < 200) { //insert '('
            int i = cur.i + (s[cur.i] == '('), j = cur.j + (t[cur.j] == '(');
            if (dp[i][j][cur.k + 1] == -1) {
                dp[i][j][cur.k + 1] = dp[cur.i][cur.j][cur.k] + 1;
                pre[i][j][cur.k + 1] = {cur.i, cur.j, cur.k};
                c[i][j][cur.k + 1] = '(';
                q.push({i, j, cur.k + 1});
            }
        }
    }
    string ans;
    int i = n + 1, j = m + 1, k = 0;
    while (i != 1 || j != 1 || k) {
        ans = c[i][j][k] + ans;
        node p = pre[i][j][k];
        i = p.i, j = p.j, k = p.k;
    }
    printf("%s\n", ans.c_str());

    return 0;
}
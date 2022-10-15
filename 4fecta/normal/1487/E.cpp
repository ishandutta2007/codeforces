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

const int MN = 200005;

int n[5], a[MN][5], m[5], dp[MN][5], u, v;
vector<int> b[MN][5];

int main() {
    boost();

    memset(dp, 0x3f, sizeof(dp));
    cin >> n[1] >> n[2] >> n[3] >> n[4];
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= n[i]; j++) cin >> a[j][i];
    }
    for (int i = 1; i <= n[1]; i++) dp[i][1] = a[i][1];
    for (int i = 1; i <= 3; i++) {
        cin >> m[i];
        for (int j = 1; j <= m[i]; j++) {
            cin >> u >> v;
            b[v][i + 1].push_back(u);
        }
        multiset<int> s;
        for (int j = 1; j <= n[i]; j++) s.insert(dp[j][i]);
        for (int j = 1; j <= n[i + 1]; j++) {
            for (int p : b[j][i + 1]) s.erase(s.find(dp[p][i]));
            if (s.size()) dp[j][i + 1] = *s.begin() + a[j][i + 1];
            for (int p : b[j][i + 1]) s.insert(dp[p][i]);
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n[4]; i++) ans = min(ans, dp[i][4]);
    printf("%d\n", ans == 0x3f3f3f3f ? -1 : ans);

    return 0;
}
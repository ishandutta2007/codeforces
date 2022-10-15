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

int n, bit[MN][30], a[MN], col[MN];
string s;

int qry(int x, int t) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & -i) ret += bit[i][t];
    return ret;
}

void upd(int x, int val, int t) {
    for (int i = x; i < MN; i += i & -i) bit[i][t] += val;
}

int main() {
    boost();

    int ans = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++) a[i + 1] = 26 - s[i] + 'a' + 1;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= 26; j++) {
            if (qry(a[i] - 1, j)) cnt++;
        }
        upd(a[i], 1, cnt + 1);
        ans = max(ans, cnt + 1);
        col[i] = cnt;
    }
    if (ans > 2) return 0 * printf("NO\n");
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d", col[i]);

    return 0;
}
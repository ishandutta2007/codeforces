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

const int MN = 100005;

int n, m, pre[MN], suf[MN];
char a[MN], b[MN];
string s, t;

int main() {
    boost();

    cin >> s >> t;
    int n = s.size(), m = t.size();
    for (int i = 1; i <= n; i++) a[i] = s[i - 1];
    for (int i = 1; i <= m; i++) b[i] = t[i - 1];
    memset(pre, 0x3f, sizeof(pre));
    memset(suf, -0x3f, sizeof(suf));
    int l = 0, r = 0, ans = 0;
    int id = 1;
    for (int i = 1; i <= m; i++) {
        while (id <= n && a[id] != b[i]) id++;
        if (id > n) break;
        pre[i] = id++;
        if (i > ans) ans = i, l = i, r = m + 1;
    }
    id = n;
    for (int i = m; i > 0; i--) {
        while (id > 0 && a[id] != b[i]) id--;
        if (id <= 0) break;
        suf[i] = id--;
        if (m - i + 1 > ans) ans = m - i + 1, l = 0, r = i;
    }
    suf[m + 1] = MN;
    int rit = 1;
    for (int i = 1; i <= m; i++) {
        while (suf[rit] <= pre[i]) rit++;
        if (m - rit + 1 + i > ans && i < rit) ans = m - rit + 1 + i, l = i, r = rit;
    }
    if (l == 0 && r == 0) printf("-");
    else {
        for (int i = 1; i <= l; i++) printf("%c", b[i]);
        for (int i = r; i <= m; i++) printf("%c", b[i]);
    }

    return 0;
}
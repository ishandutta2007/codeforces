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

int n, m, fst[MN], lst[MN]; //earliest first i, latest last i
string s, t;
char a[MN], b[MN];

int main() {
    boost();

    cin >> s >> t;
    n = s.size(), m = t.size();
    for (int i = 1; i <= n; i++) a[i] = s[i - 1];
    for (int i = 1; i <= m; i++) b[i] = t[i - 1];
    int ptr = 1;
    for (int i = 1; i <= n; i++) if (ptr <= m && a[i] == b[ptr]) fst[ptr++] = i;
    ptr = m, lst[0] = n + 1;
    for (int i = n; i > 0; i--) if (ptr && a[i] == b[ptr]) lst[m - --ptr] = i;
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = max(ans, lst[m - i] - fst[i] - 1);
        //printf("%d %d\n", fst[i], lst[m - i]);
    }
    printf("%d\n", ans);

    return 0;
}
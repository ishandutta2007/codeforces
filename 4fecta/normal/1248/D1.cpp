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

const int MN = 505;

int n, a[MN], opt, pre[MN], suf[MN], pma[MN], smi[MN];
char c;
pii ans;

void check(int i, int j) {
    memset(pre, 0, sizeof(pre));
    int cnt = 0, mi = 0x3f3f3f3f;
    swap(a[i], a[j]);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
        if (pre[i] < mi) mi = pre[i], cnt = 1;
        else if (pre[i] == mi) cnt++;
    }
    if (cnt > opt) opt = cnt, ans = {i, j};
    swap(a[i], a[j]);
}

int main() {
    boost();

    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        if (c == '(') a[i] = 1;
        else a[i] = -1;
        sum += a[i];
    }
    if (sum != 0) return 0 * printf("0\n1 1\n");
    check(1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] == a[j]) continue;
            check(i, j);
        }
    }
    printf("%d\n%d %d\n", opt, ans.f, ans.s);

    return 0;
}
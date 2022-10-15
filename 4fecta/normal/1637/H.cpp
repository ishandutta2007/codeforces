#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 500005;

int t, n, p[MN], c[MN], bit[MN];

void upd(int x, int val) {
    for (int i = x; i < MN; i += i & -i) bit[i] += val;
}

int qry(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        int inv = 0, sub = 0;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            c[i] = i - 2 * p[i] + 1;
            inv += qry(MN - 1) - qry(p[i]);
            upd(p[i], 1);
        }
        sort(c + 1, c + n + 1, greater<>());
        printf("%lld", inv);
        for (int i = 1; i <= n; i++) {
            sub += c[i];
            printf(" %lld", inv - sub - i * (i - 1) / 2);
        }
        printf("\n");
        for (int i = 1; i <= n; i++) upd(i, -1);
    }

    return 0;
}
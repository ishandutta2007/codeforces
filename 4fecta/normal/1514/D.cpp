#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

struct query {
    int l, r, i;
};

const int MN = 530005, LOG = 20;

int n, q, a[MN], l, r, bit[MN], cnt[MN][LOG], ans[MN];
vector<query> qs[MN];
vector<int> pos[MN];

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

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
        for (int s = 0; s < LOG; s++) {
            if (a[i] & (1 << s)) cnt[i][s] = cnt[i - 1][s] + 1;
            else cnt[i][s] = cnt[i - 1][s];
        }
    }
    for (int i = 1; i <= q; i++) {
        ans[i] = 1;
        cin >> l >> r;
        int len = r - l + 1, tmp = 0;
        for (int s = 0; s < LOG; s++) {
            int num = cnt[r][s] - cnt[l - 1][s];
            if (num * 2 > len) tmp |= 1 << s;
        }
        //printf("%d\n", tmp);
        if (tmp <= n) qs[tmp].push_back({l, r, i});
    }
    for (int i = 1; i <= n; i++) {
        for (int p : pos[i]) upd(p, 1);
        for (query qu : qs[i]) {
            int num = qry(qu.r) - qry(qu.l - 1), len = qu.r - qu.l + 1;
            if (num > (len + 1) / 2) {
                int rem = len - num;
                num -= rem + 1;
                ans[qu.i] = num + 1;
            } else ans[qu.i] = 1;
        }
        for (int p : pos[i]) upd(p, -1);
    }
    for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);

    return 0;
}
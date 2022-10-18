#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 2e5;

int n, val, tot, ans, bsz, a[N + 10], cnt[N + 10], sum[N + 10], lst[(N << 1) + 10], cnt1[N + 10], cnt2[N + 10];
vector<int> vec;

void update(int pos, int val) { cnt2[cnt1[pos]]--, cnt1[pos] += val, cnt2[cnt1[pos]]++; }

struct OI {
    int RP, score;
} NOIP2021, FJOI2022;

signed main() {
    NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    fr(n), bsz = sqrt(n);
    for (int i = 1; i <= n; i++) fr(a[i]), cnt[a[i]]++;
    for (int i = 1; i <= n; i++)
        if (cnt[i] > cnt[val]) val = i, tot = 1;
        else if (cnt[i] == cnt[val]) tot++;
    if (tot > 1) return printf("%d\n", n), 0;
    for (int i = 1; i <= n; i++) if (i != val && cnt[i] > bsz) vec.push_back(i);
    for (auto k : vec) {
        for (int i = 1; i <= n; i++)
            if (a[i] == k) sum[i] = sum[i - 1] - 1;
            else if (a[i] == val) sum[i] = sum[i - 1] + 1;
            else sum[i] = sum[i - 1];
        memset(lst, 0x3f, sizeof(lst));
        for (int i = 1; i <= n; i++) ans = max(ans, i - lst[n + sum[i]] + 1), lst[n + sum[i - 1]] = min(lst[n + sum[i - 1]], i);
    }
    for (int i = 1, l, r; i <= bsz; i++) {
        memset(cnt1, 0, sizeof(cnt1)), memset(cnt2, 0, sizeof(cnt2)), l = 1, r = 0;
        while (r < n) {
            update(a[++r], 1);
            while (cnt1[a[r]] > i) update(a[l++], -1);
            if (cnt2[i] > 1) ans = max(ans, r - l + 1);
        }
    }
    return printf("%d\n", ans), 0;
}
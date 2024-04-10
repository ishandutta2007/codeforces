#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 300005;

int k, n, a[MN], q, x, st[3 * MN], sum[3 * MN];
char c;

void push_up(int idx) {
    if (idx >= n / 2) {
        if (st[idx] < 2) sum[idx] = 1;
        else sum[idx] = 2;
        return;
    }
    if (st[idx] == 1) sum[idx] = sum[idx * 2];
    else if (st[idx] == 0) sum[idx] = sum[idx * 2 + 1];
    else sum[idx] = sum[idx * 2] + sum[idx * 2 + 1];
}

void build(int l, int r, int idx) {
    st[idx] = a[n - idx];
    //printf("%d %d\n", st[idx], idx);
    if (l == r) {
        if (st[idx] < 2) sum[idx] = 1;
        else sum[idx] = 2;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx * 2), build(mid + 1, r, idx * 2 + 1);
    push_up(idx);
}

void upd(int idx) {
    push_up(idx);
    if (idx / 2) upd(idx / 2);
}

int32_t main() {
    boost();

    cin >> k;
    n = 1 << k;
    for (int i = 1; i < n; i++) {
        cin >> c;
        if (c == '0' || c == '1') a[i] = c - '0';
        else a[i] = 2;
    }
    build(1, n / 2, 1);
    //printf("%d\n", sum[1]);
    cin >> q;
    while (q--) {
        cin >> x >> c;
        x = n - x;
        int val = 2;
        if (c == '0' || c == '1') val = c - '0';
        st[x] = val;
        upd(x);
        printf("%lld\n", sum[1]);
    }

    return 0;
}
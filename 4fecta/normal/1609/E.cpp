#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

struct node {
    int dp[3][3]; //min cost for this range if we start/end in i, j sections
};

const int MN = 100005;

int n, q, a[MN], t;
char c;
node st[MN * 4];

node push_up(node p, node q) {
    node ret;
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            ret.dp[i][j] = 0x3f3f3f3f;
            for (int k = i; k <= j; k++) ret.dp[i][j] = min(ret.dp[i][j], p.dp[i][k] + q.dp[k][j]);
        }
    }
    return ret;
}

void build(int l, int r, int idx) {
    if (l == r) {
        for (int i = 0; i < 3; i++) {
            for (int j = i; j < 3; j++) {
                if (a[l] == i && a[l] == j) st[idx].dp[i][j] = 1;
                else st[idx].dp[i][j] = 0;
            }
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx * 2), build(mid + 1, r, idx * 2 + 1);
    st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}

void upd(int l, int r, int x, int idx) {
    if (l == r) {
        for (int i = 0; i < 3; i++) {
            for (int j = i; j < 3; j++) {
                if (a[l] == i && a[l] == j) st[idx].dp[i][j] = 1;
                else st[idx].dp[i][j] = 0;
            }
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) upd(l, mid, x, idx * 2);
    else upd(mid + 1, r, x, idx * 2 + 1);
    st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}

int32_t main() {
    boost();

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        a[i] = c - 'a';
    }
    build(1, n, 1);
    while (q--) {
        cin >> t >> c;
        a[t] = c - 'a';
        upd(1, n, t, 1);
        printf("%lld\n", st[1].dp[0][2]);
    }

    return 0;
}
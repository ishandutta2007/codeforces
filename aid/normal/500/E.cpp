#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200 * 1000 + 5, LOGN = 20;
int p[MAXN], l[MAXN], dp[MAXN], st[4 * MAXN], nxt[MAXN][LOGN], d[MAXN][LOGN];

int get(int v, int tl, int tr, int l, int r) {
    if(tl == l && tr == r)
        return st[v];
    int tm = (tl + tr) / 2, res = 0;
    if(l < tm)
        res = max(res, get(2 * v, tl, tm, l, min(r, tm)));
    if(r > tm)
        res = max(res, get(2 * v + 1, tm, tr, max(l, tm), r));
    return res;
}

void update(int v, int tl, int tr, int pos) {
    if(tl == tr - 1) {
        st[v] = dp[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    if(pos < tm)
        update(2 * v, tl, tm, pos);
    else
        update(2 * v + 1, tm, tr, pos);
    st[v] = max(st[2 * v], st[2 * v + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i] >> l[i];
    for(int i = n - 1; i >= 0; i--) {
        int ll = i + 1, rr = upper_bound(p, p + n, p[i] + l[i]) - p;
        if(ll < rr)
            dp[i] = get(1, 0, n, ll, rr);
        dp[i] = max(dp[i], p[i] + l[i]);
        update(1, 0, n, i);
    }
    for(int i = n - 1; i >= 0; i--) {
        nxt[i][0] = upper_bound(p, p + n, dp[i]) - p;
        if(nxt[i][0] == n)
            nxt[i][0] = i;
        d[i][0] = (nxt[i][0] == i? 0 : p[nxt[i][0]] - dp[i]);
        for(int j = 1; j < LOGN; j++) {
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
            d[i][j] = d[i][j - 1] + d[nxt[i][j - 1]][j - 1];
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int ans = 0;
        for(int j = LOGN - 1; j >= 0; j--)
            if(nxt[x][j] <= y) {
                ans += d[x][j];
                x = nxt[x][j];
            }
        if(p[y] > dp[x])
            ans += p[y] - dp[x];
        cout << ans << '\n';
    }
    return 0;
}
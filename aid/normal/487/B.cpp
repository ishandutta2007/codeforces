#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5, LOGN = 20, INF = 1000 * 1000 * 1000 + 5;
int a[MAXN], smin[LOGN][MAXN], smax[LOGN][MAXN],
    logs[MAXN], dp[MAXN], st[4 * MAXN];

int getdiff(int l, int r) {
    int len = logs[r - l], mina = min(smin[len][l], smin[len][r - (1 << len)]),
        maxa = max(smax[len][l], smax[len][r - (1 << len)]);
    return maxa - mina;
}

int get(int pos, int s) {
    int l = -1, r = pos - 1;
    while(l < r - 1) {
        int m = (l + r) / 2;
        if(getdiff(m, pos) <= s)
            r = m;
        else
            l = m;
    }
    return r;
}

void buildst(int v, int tl, int tr) {
    if(tl == tr - 1) {
        st[v] = dp[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm);
    buildst(2 * v + 1, tm, tr);
    st[v] = min(st[2 * v], st[2 * v + 1]);
}

int getMin(int v, int tl, int tr, int l, int r) {
    if(tl == l && tr == r)
        return st[v];
    int tm = (tl + tr) / 2, res = INF;
    if(l < tm)
        res = min(res, getMin(2 * v, tl, tm, l, min(r, tm)));
    if(r > tm)
        res = min(res, getMin(2 * v + 1, tm, tr, max(l, tm), r));
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
    st[v] = min(st[2 * v], st[2 * v + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, s, l;
    cin >> n >> s >> l;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        smin[0][i] = a[i];
        smax[0][i] = a[i];
    }
    for(int i = 2; i <= n; i++)
        logs[i] = logs[i / 2] + 1;
    for(int i = 1; i <= logs[n]; i++)
        for(int j = 0; j + (1 << i) <= n; j++)
            smin[i][j] = min(smin[i - 1][j], smin[i - 1][j + (1 << (i - 1))]);
    for(int i = 1; i <= logs[n]; i++)
        for(int j = 0; j + (1 << i) <= n; j++)
            smax[i][j] = max(smax[i - 1][j], smax[i - 1][j + (1 << (i - 1))]);
    for(int i = 0; i <= n; i++)
        dp[i] = INF;
    dp[0] = 0;
    buildst(1, 0, n + 1);
    for(int i = l; i <= n; i++) {
        int ll = get(i, s), rr = i - l + 1;
        if(ll < rr)
            dp[i] = getMin(1, 0, n + 1, ll, rr) + 1;
        dp[i] = min(dp[i], INF);
        update(1, 0, n + 1, i);
    }
    cout << (dp[n] >= INF? -1 : dp[n]) << '\n';
    return 0;
}
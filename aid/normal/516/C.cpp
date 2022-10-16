#include <iostream>

using namespace std;

const int MAXN = 200 * 1000 + 5, LOGN = 20;
int d[MAXN], h[MAXN], logs[MAXN];
long long sp[2][LOGN][MAXN], st[4 * MAXN];

long long getMax(int t, int l, int r) {
    int len = logs[r - l];
    return max(sp[t][len][l], sp[t][len][r - (1 << len)]);
}

void buildst(int v, int tl, int tr) {
    if(tl == tr - 1) {
        st[v] = -1;
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm);
    buildst(2 * v + 1, tm, tr);
    st[v] = max(getMax(0, tl, tm) + getMax(1, tm, tr),
                max(st[2 * v], st[2 * v + 1]));
}

long long get(int v, int tl, int tr, int l, int r) {
    if(tl == l && tr == r)
        return st[v];
    int tm = (tl + tr) / 2;
    if(l < tm) {
        if(r > tm) {
            long long resl = get(2 * v, tl, tm, l, tm),
                resr = get(2 * v + 1, tm, tr, tm, r),
                resm = getMax(0, l, tm) + getMax(1, tm, r);
            return max(max(resl, resr), resm);
        }
        else
            return get(2 * v, tl, tm, l, r);
    }
    else
        return get(2 * v + 1, tm, tr, l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> d[i];
    for(int i = 0; i < n; i++)
        cin >> h[i];
    for(int i = 0; i < n; i++)
        d[n + i] = d[i];
    for(int i = 0; i < n; i++)
        h[n + i] = h[i];
    sp[0][0][0] = 2 * h[0];
    sp[1][0][0] = 2 * h[0];
    long long sum = d[0];
    for(int i = 1; i < 2 * n; i++) {
        sp[0][0][i] = 2 * h[i] - sum;
        sp[1][0][i] = 2 * h[i] + sum;
        sum += d[i];
    }
    for(int i = 2; i <= 2 * n; i++)
        logs[i] = logs[i / 2] + 1;
    for(int ii = 0; ii < 2; ii++)
        for(int i = 1; i <= logs[2 * n]; i++)
            for(int j = 0; j + (1 << i) <= 2 * n; j++)
                sp[ii][i][j] = max(sp[ii][i - 1][j],
                                   sp[ii][i - 1][j + (1 << (i - 1))]);
    buildst(1, 0, 2 * n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a <= b)
            cout << get(1, 0, 2 * n, b + 1, n + a) << '\n';
        else
            cout << get(1, 0, 2 * n, b + 1, a) << '\n';
    }
    return 0;
}
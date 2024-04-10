#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 50 * 1000 + 5;
int s[MAXN], st[4 * MAXN][2][2], a[2][2], b[2][2], n, mod;
pair<long long, int> v[MAXN];

void mul(int a[2][2], int b[2][2]) {
    int c[2][2];
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++) {
            c[i][j] = 0;
            for(int k = 0; k < 2; k++)
                c[i][j] = (c[i][j] + (long long)a[i][k] * b[k][j]) % mod;
        }
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            a[i][j] = c[i][j];
}

void matPow(int a[2][2], long long p) {
    int b[2][2] = {{1, 0}, {0, 1}};
    while(p) {
        if(p & 1)
            mul(b, a);
        p >>= 1;
        mul(a, a);
    }
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            a[i][j] = b[i][j];
}

void buildst(int v, int tl, int tr) {
    if(tl == tr - 1) {
        st[v][0][0] = s[tl + 1];
        st[v][0][1] = 1;
        st[v][1][0] = s[tl];
        st[v][1][1] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm);
    buildst(2 * v + 1, tm, tr);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            st[v][i][j] = st[2 * v][i][j];
    mul(st[v], st[2 * v + 1]);
}

void get(int v, int tl, int tr, int l, int r, int res[2][2]) {
    if(tl == l && tr == r) {
        mul(res, st[v]);
        return;
    }
    int tm = (tl + tr) / 2;
    if(l < tm)
        get(2 * v, tl, tm, l, min(r, tm), res);
    if(r > tm)
        get(2 * v + 1, tm, tr, max(l, tm), r, res);
}

void f(long long l, long long r) {
    long long ll = (l + n - 1) / n, rr = r / n;
    l %= n;
    r %= n;
    if(ll > rr) {
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                b[i][j] = (i == j);
        if(l < r)
            get(1, 0, n, l, r, b);
        mul(a, b);
        return;
    }
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            b[i][j] = (i == j);
    if(l)
        get(1, 0, n, l, n, b);
    mul(a, b);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            b[i][j] = (i == j);
    get(1, 0, n, 0, n, b);
    matPow(b, rr - ll);
    mul(a, b);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            b[i][j] = (i == j);
    if(r)
        get(1, 0, n, 0, r, b);
    mul(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long k;
    cin >> k >> mod >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    s[n] = s[0];
    buildst(1, 0, n);
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> v[i].first >> v[i].second;
    sort(v, v + m);
    a[0][0] = 1;
    a[1][1] = 1;
    long long prev = 0;
    for(int i = 0; i < m; i++) {
        if(v[i].first > k)
            break;
        if(v[i].first - 1 > prev)
            f(prev, v[i].first - 1);
        if(!i || v[i - 1].first != v[i].first - 1) {
            b[0][0] = v[i].second;
            b[0][1] = 1;
            b[1][0] = s[(v[i].first - 1) % n];
            b[1][1] = 0;
            mul(a, b);
        }
        prev = v[i].first;
        if(v[i].first == k)
            break;
        b[0][0] = (i + 1 < m? (v[i + 1].first == v[i].first + 1?
                               v[i + 1].second : s[(v[i].first + 1) % n]) :
                   s[(v[i].first + 1) % n]);
        b[0][1] = 1;
        b[1][0] = v[i].second;
        b[1][1] = 0;
        mul(a, b);
        prev = v[i].first + 1;
    }
    f(prev, k);
    cout << a[0][1] << '\n';
    return 0;
}
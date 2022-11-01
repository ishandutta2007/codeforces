#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld EPS = 1e-6;
const ll INF = 1e9 + 10;
const int M = 53;
const int N = 80003;

int a[N];
int lft[N];
int last[N];
int d[M][2 * N], ar[M][N];
int ad[M][2 * N];

void build(int k, int v, int tl, int tr) {
    if (tl == tr) {
        d[k][v] = ar[k][tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(k, 2 * v, tl, tm);
    build(k, 2 * v + 1, tm + 1, tr);
    d[k][v] = max(d[k][2 * v], d[k][2 * v + 1]);
}

void push(int k, int v, int tl, int tr) {
    if (!ad[k][v]) return;
    if (tl != tr) {
        ad[k][2 * v] += ad[k][v];
        ad[k][2 * v + 1] += ad[k][v];
    }
    d[k][v] += ad[k][v];
    ad[k][v] = 0;
    return;
}

void add(int k, int v, int tl, int tr, int l, int r) {
    push(k, v, tl, tr);
    if (tl > r || l > tr) return;
    if (l <= tl && tr <= r) {
        ad[k][v]++;
        push(k, v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    add(k, 2 * v, tl, tm, l, r);
    add(k, 2 * v + 1, tm + 1, tr, l, r);
    d[k][v] = max(d[k][v * 2], d[k][v * 2 + 1]);
}

int getMax(int k, int v, int tl, int tr, int l, int r) {
    push(k, v, tl, tr);
    if (tl > r || l > tr) return -INF;
    if (l <= tl && tr <= r) return d[k][v];
    int tm = (tl + tr) / 2;
    return max(getMax(k, 2 * v, tl, tm, l, r),
            getMax(k, 2 * v + 1, tm + 1, tr, l, r));
}

int main() {
    //srand(time(NULL));
    //ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int n, k1;
    cin >> n >> k1;
    frab(i, 1, 1 + n) {
        cin >> a[i];
        lft[i] = last[a[i]];
        last[a[i]] = i;
    }

    frab(k, 1, k1 + 1) {
        build(k - 1, 1, 0, n);
        frab(i, 1, 1 + n) {
            add(k - 1, 1, 0, n, lft[i], i - 1);
            ar[k][i] = getMax(k - 1, 1, 0, n, 0, i - 1);
            ar[k][i] = max(ar[k][i], ar[k][i - 1]);
        }
    }
    cout << ar[k1][n];
}
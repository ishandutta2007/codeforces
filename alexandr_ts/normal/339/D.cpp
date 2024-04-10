#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

const int N = 2e5;
const int INF = 2e9;

int a[N], t[4 * N];

void build(int v, int l, int r, int lvl) {
    if (l == r) {
        t[v] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m, lvl - 1);
    build(2 * v + 1, m + 1, r, lvl - 1);
    if (lvl % 2)
        t[v] = t[2 * v] ^ t[2 * v + 1];
    else
        t[v] = t[2 * v] | t[2 * v + 1];
}

void update(int v, int l, int r, int pos, int x, int lvl) {
    if (l == r) {
        t[v] = x;
        return;
    }
    int m = (l + r) / 2;
    if (l <= pos && pos <= m)
        update(2 * v, l, m, pos, x, lvl - 1);
    else
        update(2 * v + 1, m + 1, r, pos, x, lvl - 1);
    if (lvl % 2)
        t[v] = t[2 * v] ^ t[2 * v + 1];
    else
        t[v] = t[2 * v] | t[2 * v + 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int n, m, p, b;
    cin >> n >> m;
    fr(i, (1 << n))
        cin >> a[i];
    build(1, 0, (1 << n) - 1, (1 + n));
    fr(i, m) {
        int pos, x;
        cin >> pos >> x;
        update(1, 0, (1 << n) - 1, pos - 1, x, (1 + n));
        cout << t[1] << endl;
    }

}
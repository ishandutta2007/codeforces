#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

#define M 100100
#define long long long
#define mp make_pair
#define INF 1000000000

set<pair<int, int> > s;
int n, m;
long t[8 * M], ss[8 * M];

void upd(int v, int l, int r, int le, int re, long val) {
    if (l == le && r == re) {
        ss[v] += val;
        return;
    }

    int m = (l + r) / 2;

    if (le < m)
        upd(2 * v, l, m, le, min(m, re), val);

    if (m < re)
        upd(2 * v + 1, m, r, max(le, m), re, val);

    t[v] += (re - le) * val;
}

long get(int v, int l, int r, int le, int re) {
    if (l == le && r == re)
        return t[v] + (re - le) * ss[v];

    int m = (l + r) / 2;
    long ans = 0;
    if (le < m)
        ans += get(2 * v, l, m, le, min(m, re));
    if (m < re)
        ans += get(2 * v + 1, m, r, max(le, m), re);

    return ans + (re - le) * ss[v];
}

int pred(int x) {
    auto it = s.upper_bound(make_pair(x, INF));
    --it;
    return it -> first;
}

int col(int x) {
    auto it = s.upper_bound(make_pair(x, INF));
    --it;
    return it -> second;
}

int nxt(int x) {
    return s.upper_bound(make_pair(x, INF)) -> first;
}

void add(int x, int col) {
    s.insert(make_pair(x, col));
}

void kill() {
    cin >> n >> m;
    
    s.insert(make_pair(n + 1, 0));
    s.insert(make_pair(0, 0));
    for (int i = 1; i <= n; ++i)
        s.insert(make_pair(i, i));

    for (int ii = 0, t, l, r, x; ii < m; ++ii) {
        cin >> t >> l >> r;
        ++r;
        if (t == 1) {
            cin >> x;

            if (r != pred(r))
                add(r, col(r));

            if (l != pred(l))
                add(l, col(l));


            for (int i = l, j; i != r; ) {
                j = nxt(i);
                //cout << "do " << i << "-" << j << " in " << abs(col(i) - x) << "\n";
                upd(1, 0, n + 1, i, j, abs(col(i) - x));
                i = j;
            }


            for (int i = l, j; i != r; ) {
                j = nxt(i);
                s.erase(make_pair(i, col(i)));
                i = j;
            }

            add(l, x);
        }

        if (t == 2) {
            cout << get(1, 0, n + 1, l, r) << "\n";
        }
    }
}


int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    kill();

    return 0;
}
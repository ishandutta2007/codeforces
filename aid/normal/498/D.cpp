#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5, T = 60;
int st[4 * MAXN][T], a[MAXN];

void buildst(int v, int tl, int tr) {
    if(tl == tr - 1) {
        for(int i = 0; i < T; i++)
            st[v][i] = ((i % a[tl])? 1 : 2);
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm);
    buildst(2 * v + 1, tm, tr);
    for(int i = 0; i < T; i++)
        st[v][i] = st[2 * v][i] + st[2 * v + 1][(i + st[2 * v][i]) % T];
}

int get(int v, int tl, int tr, int l, int r, int t) {
    if(l == tl && r == tr)
        return t + st[v][t % T];
    int tm = (tl + tr) / 2;
    if(l < tm)
        t = get(2 * v, tl, tm, l, min(r, tm), t);
    if(r > tm)
        t = get(2 * v + 1, tm, tr, max(l, tm), r, t);
    return t;
}

void update(int v, int tl, int tr, int pos) {
    if(tl == tr - 1) {
        for(int i = 0; i < T; i++)
            st[v][i] = ((i % a[tl])? 1 : 2);
        return;
    }
    int tm = (tl + tr) / 2;
    if(pos < tm)
        update(2 * v, tl, tm, pos);
    else
        update(2 * v + 1, tm, tr, pos);
    for(int i = 0; i < T; i++)
        st[v][i] = st[2 * v][i] + st[2 * v + 1][(i + st[2 * v][i]) % T];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    buildst(1, 0, n);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if(c == 'A') {
            x--;
            y--;
            cout << get(1, 0, n, x, y, 0) << '\n';
        }
        else {
            x--;
            a[x] = y;
            update(1, 0, n, x);
        }
    }
    return 0;
}
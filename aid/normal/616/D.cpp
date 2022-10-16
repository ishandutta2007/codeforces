#include <iostream>

using namespace std;

const int MAXN = 500 * 1000 + 5, MAXX = 1000 * 1000 + 5;
int a[MAXN], nxt[MAXN], lst[MAXX], st[4 * MAXN];

void buildst(int v, int tl, int tr) {
    if(tl == tr - 1) {
        st[v] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm);
    buildst(2 * v + 1, tm, tr);
    st[v] = st[2 * v] + st[2 * v + 1];
}

void update(int v, int tl, int tr, int pos, int val) {
    if(tl == tr - 1) {
        st[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if(pos < tm)
        update(2 * v, tl, tm, pos, val);
    else
        update(2 * v + 1, tm, tr, pos, val);
    st[v] = st[2 * v] + st[2 * v + 1];
}

int get(int v, int tl, int tr, int k) {
    if(tl == tr - 1)
        return tl;
    int tm = (tl + tr) / 2;
    if(k < st[2 * v])
        return get(2 * v, tl, tm, k);
    else
        return get(2 * v + 1, tm, tr, k - st[2 * v]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < MAXX; i++)
        lst[i] = n;
    for(int i = n - 1; i >= 0; i--) {
        nxt[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    for(int i = 0; i <= n; i++)
        a[i] = 0;
    for(int i = 0; i < MAXX; i++)
        if(lst[i] < n)
            a[lst[i]] = 1;
    buildst(1, 0, n + 1);
    int l = 0, r = 0;
    for(int i = 0; i < n; i++) {
        int j = get(1, 0, n + 1, k);
        if(j - i > r - l) {
            l = i;
            r = j;
        }
        update(1, 0, n + 1, i, 0);
        if(nxt[i] < n)
            update(1, 0, n + 1, nxt[i], 1);
    }
    cout << l + 1 << ' ' << r << '\n';
    return 0;
}
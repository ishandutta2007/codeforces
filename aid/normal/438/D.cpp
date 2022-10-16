#include <iostream>

using namespace std;

struct Node {
    int maxa;
    long long sum;
};

const int MAXN = 100 * 1000 + 5;
Node st[4 * MAXN];
int a[MAXN];

void buildst(int v, int tl, int tr) {
    if(tl + 1 == tr) {
        st[v].maxa = tl;
        st[v].sum = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm);
    buildst(2 * v + 1, tm, tr);
    if(a[st[2 * v].maxa] > a[st[2 * v + 1].maxa])
        st[v].maxa = st[2 * v].maxa;
    else
        st[v].maxa = st[2 * v + 1].maxa;
    st[v].sum = st[2 * v].sum + st[2 * v + 1].sum;
}

long long getSum(int v, int tl, int tr, int l, int r) {
    if(l == tl && r == tr)
        return st[v].sum;
    int tm = (tl + tr) / 2;
    long long res0 = 0, res1 = 0;
    if(l < tm)
        res0 = getSum(2 * v, tl, tm, l, min(r, tm));
    if(r > tm)
        res1 = getSum(2 * v + 1, tm, tr, max(l, tm), r);
    return res0 + res1;
}

int getMax(int v, int tl, int tr, int l, int r) {
    if(l == tl && r == tr)
        return st[v].maxa;
    int tm = (tl + tr) / 2, res0 = -1, res1 = -1;
    if(l < tm)
        res0 = getMax(2 * v, tl, tm, l, min(r, tm));
    if(r > tm)
        res1 = getMax(2 * v + 1, tm, tr, max(l, tm), r);
    if(res0 == -1)
        return res1;
    if(res1 == -1)
        return res0;
    if(a[res0] > a[res1])
        return res0;
    return res1;
}

void update(int v, int tl, int tr, int k, int x) {
    if(tl + 1 == tr) {
        a[k] = x;
        st[v].sum = x;
        return;
    }
    int tm = (tl + tr) / 2;
    if(k < tm)
        update(2 * v, tl, tm, k, x);
    else
        update(2 * v + 1, tm, tr, k, x);
    if(a[st[2 * v].maxa] > a[st[2 * v + 1].maxa])
        st[v].maxa = st[2 * v].maxa;
    else
        st[v].maxa = st[2 * v + 1].maxa;
    st[v].sum = st[2 * v].sum + st[2 * v + 1].sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    buildst(1, 0, n);
    for(int i = 0; i < m; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r;
            cin >> l >> r;
            l--;
            cout << getSum(1, 0, n, l, r) << '\n';
        }
        else if(type == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            while(true) {
                int p = getMax(1, 0, n, l, r);
                if(a[p] < x)
                    break;
                update(1, 0, n, p, a[p] % x);
            }
        }
        else {
            int k, x;
            cin >> k >> x;
            k--;
            update(1, 0, n, k, x);
        }
    }
    return 0;
}
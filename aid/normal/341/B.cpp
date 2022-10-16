#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
int st[4 * MAXN];

int getMax(int v, int tl, int tr, int l, int r) {
    if(l == tl && r == tr)
        return st[v];
    int tm = (tl + tr) / 2;
    int m1 = 0, m2 = 0;
    if(l < tm)
        m1 = getMax(2 * v, tl, tm, l, min(r, tm));
    if(r > tm)
        m2 = getMax(2 * v + 1, tm, tr, max(l, tm), r);
    return max(m1, m2);
}

void change(int v, int tl, int tr, int i, int x) {
    if(tl == tr - 1) {
        st[v] = x;
        return;
    }
    int tm =(tl + tr) / 2;
    if(i < tm)
        change(2 * v, tl, tm, i, x);
    else
        change(2 * v + 1, tm, tr, i, x);
    st[v] = max(st[2 * v], st[2 * v + 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        int k = a[i] > 1? getMax(1, 1, n + 1, 1, a[i]) : 0;
        change(1, 1, n + 1, a[i], k + 1);
    }
    cout << st[1] << '\n';
}
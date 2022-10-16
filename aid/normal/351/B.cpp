#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 4000;

int st[4 * MAXN];

void add(int v, int tl, int tr, int k) {
    st[v]++;
    if(tl == tr)
        return;
    int m = (tl + tr) / 2;
    if(k <= m)
        add(2 * v, tl, m, k);
    else
        add(2 * v + 1, m + 1, tr, k);
}

int get_sum(int v, int tl, int tr, int l, int r) {
    if(tl == l && tr == r)
        return st[v];
    int m = (tl + tr) / 2, res = 0;
    if(l <= m)
        res += get_sum(2 * v, tl, m, l, min(m, r));
    if(r > m)
        res += get_sum(2 * v + 1, m + 1, tr, max(m + 1, l), r);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int inv = 0;
    for(int i = n - 1; i >= 0; i--) {
        inv += get_sum(1, 0, MAXN - 1, 0, v[i] - 1);
        add(1, 0, MAXN - 1, v[i]);
    }
    double ans = (inv / 2) * 4;
    if(inv % 2)
        ans += 1;
    cout.setf(ios::fixed);
    cout.precision(7);
    cout << ans << '\n';
}
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5, INF = 1000 * 1000 * 1000 + 5;
int c[MAXN], c1[MAXN], st[4 * MAXN], ans[MAXN];
pair<int, int> a[MAXN];
pair<int, pair<int, int> > bc[MAXN];

void buildst(int v, int tl, int tr) {
    if(tl == tr - 1) {
        st[v] = tl;
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm);
    buildst(2 * v + 1, tm, tr);
    if(c[bc[st[2 * v]].second.second] < c[bc[st[2 * v + 1]].second.second])
        st[v] = st[2 * v];
    else
        st[v] = st[2 * v + 1];
}

int get(int v, int tl, int tr, int l, int r) {
    if(l == tl && r == tr)
        return st[v];
    int tm = (tl + tr) / 2, res1 = -1, res2 = -1;
    if(l < tm)
        res1 = get(2 * v, tl, tm, l, min(r, tm));
    if(r > tm)
        res2 = get(2 * v + 1, tm, tr, max(l, tm), r);
    if(res1 == -1)
        return res2;
    if(res2 == -1)
        return res1;
    if(c[bc[res1].second.second] < c[bc[res2].second.second])
        return res1;
    return res2;
}

void update(int v, int tl, int tr, int k, int x) {
    if(tl == tr - 1) {
        c[bc[k].second.second] = x;
        return;
    }
    int tm = (tl + tr) / 2;
    if(k < tm)
        update(2 * v, tl, tm, k, x);
    else
        update(2 * v + 1, tm, tr, k, x);
    if(c[bc[st[2 * v]].second.second] < c[bc[st[2 * v + 1]].second.second])
        st[v] = st[2 * v];
    else
        st[v] = st[2 * v + 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, s;
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for(int i = 0; i < n; i++) {
        cin >> bc[i].first;
        bc[i].second.second = i;
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        c1[i] = c[i];
        bc[i].second.first = c[i];
    }
    sort(a, a + m);
    sort(bc, bc + n);
    int l = 0, r = m;
    while(l < r - 1) {
        buildst(1, 0, n);
        int d = (l + r) / 2, stud = (m + d - 1) / d, k = m - 1, sum = 0;
        bool b = true;
        for(int i = 0; i < stud; i++, k -= d) {
            int p = lower_bound(bc, bc + n,
                                make_pair(a[k].first, make_pair(0, 0))) - bc;
            if(p >= n) {
                b = false;
                break;
            }
            int q = get(1, 0, n, p, n), cost = c[bc[q].second.second];
            if(sum + cost > s) {
                b = false;
                break;
            }
            sum += cost;
            update(1, 0, n, q, INF);
        }
        if(b)
            r = d;
        else
            l = d;
        for(int i = 0; i < n; i++)
            c[i] = c1[i];
    }
    buildst(1, 0, n);
    int d = r, stud = (m + d - 1) / d, k = m - 1, sum = 0;
    for(int i = 0; i < stud; i++, k -= d) {
        int p = lower_bound(bc, bc + n,
                            make_pair(a[k].first, make_pair(0, 0))) - bc;
        if(p >= n) {
            cout << "NO\n";
            return 0;
        }
        int q = get(1, 0, n, p, n), cost = c[bc[q].second.second];
        if(sum + cost > s) {
            cout << "NO\n";
            return 0;
        }
        sum += cost;
        for(int j = k; j >= max(0, k - d); j--)
            ans[a[j].second] = bc[q].second.second;
        update(1, 0, n, q, INF);
    }
    cout << "YES\n";
    for(int i = 0; i < m; i++)
        cout << ans[i] + 1 << ' ';
    cout << '\n';
    return 0;
}
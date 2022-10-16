#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 200 * 1000 + 5;
int l[MAXN], r[MAXN], a[MAXN], b[MAXN], c[MAXN],
    pos[MAXN], st[4 * MAXN];
pair<int, pair<char, int> > p[4 * MAXN];
pair<int, int> pp[MAXN];

void solve0(int n, int m, long long &ans, int &ans0, int &ans1) {
    int evs = 0;
    for(int i = 0; i < n; i++) {
        p[evs++] = make_pair(l[i], make_pair(0, i));
        p[evs++] = make_pair(r[i], make_pair(1, i));
    }
    for(int i = 0; i < m; i++)
        p[evs++] = make_pair(b[i], make_pair(2, i));
    sort(p, p + evs);
    set< pair<int, int> > st;
    long long res = 0;
    int res0 = -1, res1 = -1;
    for(int i = 0; i < evs; i++) {
        char ch = p[i].second.first;
        int id = p[i].second.second;
        if(ch == 0)
            st.insert(make_pair(l[id], id));
        else if(ch == 1)
            st.erase(make_pair(l[id], id));
        else {
            if(st.empty())
                continue;
            int ll = max(st.begin()->first, a[id]);
            long long x = (long long)(b[id] - ll) * c[id];
            if(x > res) {
                res = x;
                res0 = st.begin()->second;
                res1 = id;
            }
        }
    }
    if(res > ans) {
        ans = res;
        ans0 = res0;
        ans1 = res1;
    }
}

void buildst(int v, int tl, int tr) {
    if(tl == tr - 1) {
        st[v] = -1;
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm);
    buildst(2 * v + 1, tm, tr);
    st[v] = -1;
}

void update(int v, int tl, int tr, int k, int id) {
    if(tl == tr - 1) {
        st[v] = id;
        return;
    }
    int tm = (tl + tr) / 2;
    if(k < tm)
        update(2 * v, tl, tm, k, id);
    else
        update(2 * v + 1, tm, tr, k, id);
    if(st[2 * v] == -1)
        st[v] = st[2 * v + 1];
    else if(st[2 * v + 1] == -1)
        st[v] = st[2 * v];
    else if(c[st[2 * v]] > c[st[2 * v + 1]])
        st[v] = st[2 * v];
    else
        st[v] = st[2 * v + 1];
}

int get(int v, int tl, int tr, int l, int r) {
    if(l == tl && r == tr)
        return st[v];
    int tm = (tl + tr) / 2, res0 = -1, res1 = -1;
    if(l < tm)
        res0 = get(2 * v, tl, tm, l, min(r, tm));
    if(r > tm)
        res1 = get(2 * v + 1, tm, tr, max(l, tm), r);
    if(res0 == -1)
        return res1;
    if(res1 == -1)
        return res0;
    if(c[res0] > c[res1])
        return res0;
    return res1;
}

void solve1(int n, int m, long long &ans, int &ans0, int &ans1) {
    for(int i = 0; i < m; i++)
        pp[i] = make_pair(a[i], i);
    sort(pp, pp + m);
    for(int i = 0; i < m; i++)
        pos[pp[i].second] = i;
    buildst(1, 0, m);
    int evs = 0;
    for(int i = 0; i < n; i++)
        p[evs++] = make_pair(r[i], make_pair(0, i));
    for(int i = 0; i < m; i++) {
        p[evs++] = make_pair(a[i], make_pair(1, i));
        p[evs++] = make_pair(b[i], make_pair(2, i));
    }
    sort(p, p + evs);
    long long res = 0;
    int res0 = -1, res1 = -1;
    for(int i = 0; i < evs; i++) {
        char ch = p[i].second.first;
        int id = p[i].second.second;
        if(ch == 0) {
            int pref = lower_bound(pp, pp + m, make_pair(l[id] + 1, -1)) - pp;
            if(!pref)
                continue;
            int id1 = get(1, 0, m, 0, pref);
            if(id1 == -1)
                continue;
            long long x = (long long)(r[id] - l[id]) * c[id1];
            if(x > res) {
                res = x;
                res0 = id;
                res1 = id1;
            }
        }
        else if(ch == 1)
            update(1, 0, m, pos[id], id);
        else
            update(1, 0, m, pos[id], -1);
    }
    if(res > ans) {
        ans = res;
        ans0 = res0;
        ans1 = res1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    for(int i = 0; i < m; i++)
        cin >> a[i] >> b[i] >> c[i];
    long long ans = 0;
    int ans0 = -1, ans1 = -1;
    solve0(n, m, ans, ans0, ans1);
    solve1(n, m, ans, ans0, ans1);
    for(int i = 0; i < n; i++) {
        swap(l[i], r[i]);
        l[i] *= -1;
        r[i] *= -1;
    }
    for(int i = 0; i < m; i++) {
        swap(a[i], b[i]);
        a[i] *= -1;
        b[i] *= -1;
    }
    solve0(n, m, ans, ans0, ans1);
    cout << ans << '\n';
    if(ans > 0)
        cout << ans0 + 1 << ' ' << ans1 + 1 << '\n';
    return 0;
}
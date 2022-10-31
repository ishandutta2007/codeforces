#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long
 
int nxt() {
    int x;
    cin >> x;
    return x;
}
 
struct Edge {
    int v, u, w, idx;
};

int timer = 0;
vector <vector <int>> t, st;
vector <vector <int>> sets;
vector <int> where;

void unite(int v, int u) {
    v = where[v], u = where[u];
    if (sz(sets[v]) > sz(sets[u]))
        swap(v, u);
    for (int i : sets[v]) {
        t[i].pb(timer);
        st[i].pb(u);
        sets[u].pb(i);
        where[i] = u;
    }
}

bool check(int m, int v, int u) {
    return st[v][--upper_bound(all(t[v]), m) - t[v].begin()] == st[u][--upper_bound(all(t[u]), m) - t[u].begin()];
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n = nxt(), m = nxt();
    vector <Edge> a(m);
    forn (i, 0, m) 
        a[i] = {nxt() - 1, nxt() - 1, nxt(), i};
    t = st = sets = vector <vector <int>> (n);
    where = vector <int> (n);
    forn (i, 0, n) 
        t[i].pb(0), st[i].pb(i), sets[i].pb(i), where[i] = i;

    auto cmp = [&](Edge a, Edge b){return a.w < b.w;};
    sort(all(a), cmp);
    vector <int> used;
    vector <int> useless;
    forn (i, 0, m) {
        if (where[a[i].v] != where[a[i].u]) {
            timer++;
            unite(a[i].v, a[i].u);
            used.pb(i);
        } else {
            useless.pb(i);
        }
    }

    /*forn (i, 0, n) {
        cout << i << ":\n";
        forn (j, 0, sz(t[i]))
            cout << t[i][j] << " " << st[i][j] << "\n";
        cout << "\n";
    }*/

    vector <pii> ans;
    for (int i : useless) {
        //cout << a[i].v << " " << a[i].u << "\n";

        int l = 0, r = sz(used);
        while (r - l > 1) {
            int mid = (l + r) / 2;
            //cout << mid << " " << check(mid, a[i].v, a[i].u) << "\n";
            if (check(mid, a[i].v, a[i].u))
                r = mid;
            else 
                l = mid;
        }
        //cout << used[r] << " " << r << "\n";
        ans.eb(a[i].idx, a[used[l]].w);
    }
    sort(all(ans));
    for (pii i : ans)
        cout << i.sc << "\n";
    return 0;
}
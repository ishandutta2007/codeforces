#pragma GCC optmize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;

int h;
vector <vector <int>> gr, rgr;
vector <bool> used;
vector <int> ord;

void dfs1(int v) {
    //cout << v << " ";
    used[v] = 1;
    for (auto u : gr[v])
        if (!used[u])
            dfs1(u);
    ord.pb(v);
}

vector <int> col;
void dfs2(int v, int cur) {
    col[v] = cur;
    for (auto u : rgr[v])
        if (!col[u])
            dfs2(u, cur);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m >> h;
    gr.resize(n), rgr.resize(n);
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    forn (i, 0, m) {
        int t1, t2;
        cin >> t1 >> t2;
        t1--, t2--;
        if ((a[t1] + 1) % h == a[t2]) {
            gr[t1].pb(t2);
            rgr[t2].pb(t1);
        }
        if ((a[t2] + 1) % h == a[t1]) {
            gr[t2].pb(t1);
            rgr[t1].pb(t2);
        }
    }
    used.resize(n);
    forn (i, 0, n)
        if (!used[i])
            dfs1(i);
    reverse(all(ord));
    //forn (i, 0, n)
    //    cout << ord[i] << " ";
    col.resize(n);
    int t = 1;
    forn (i, 0, n)
        if (!col[ord[i]])
            dfs2(ord[i], t++);
    vector <vector <int>> b(t);
    forn (i, 0, n)
        b[col[i]].pb(i);
    //forn (i, 0, n)
    //    cout << col[i] << " ";
    vector <int> ans(n + 1);
    forn (i, 1, t) {
        bool f = 1;
        forn (j, 0, b[i].size())
            forn (k, 0, gr[b[i][j]].size())
                if (col[b[i][j]] != col[gr[b[i][j]][k]])
                    f = 0;
        if (f && b[i].size() < ans.size())
            ans = b[i];
    }
    sort(all(ans));
    cout << ans.size() << "\n";
    forn (i, 0, ans.size())
        cout << ans[i] + 1 << " ";
    return 0;
}
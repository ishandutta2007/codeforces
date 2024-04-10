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

vector <vector <int>> gr;
vector <vector <int>> edg;
vector <int> tmp;
vector <bool> used;
int n, m;

void dfs1(int v) {
    used[v] = 1;
    for (auto u : gr[v])
        if (!used[u])
            dfs1(u);
    tmp.pb(v);
}

bool f;
vector <int> col;

void dfs2(int v) {
    //cout << v << " ";
    col[v] = 1;
    for (auto u : gr[v]) {
        if (col[u] == 1)
            f = 0;
        if (!col[u])
            dfs2(u);
    }
    col[v] = 2;
}

vector <int> ans;

bool check(int mid) {
    //cout << mid << " ";
    gr.clear();
    gr.resize(n);
    forn (i, 0, m)
        if (edg[i][2] > mid)
            gr[edg[i][0]].pb(edg[i][1]);
    tmp.clear();
    used.clear();
    used.resize(n);
    forn (i, 0, n)
        if (!used[i])
            dfs1(i);
    reverse(all(tmp));
    vector <int> ord(n);
    forn (i, 0, n)
        ord[tmp[i]] = i;
    ans.clear();
    forn (i, 0, m) {
        if (edg[i][2] <= mid && ord[edg[i][0]] < ord[edg[i][1]])
            gr[edg[i][0]].pb(edg[i][1]);
        if (edg[i][2] <= mid && ord[edg[i][0]] > ord[edg[i][1]]) {
            gr[edg[i][1]].pb(edg[i][0]);
            ans.pb(i + 1);
        }
    }
    col.clear();
    col.resize(n);
    f = 1;
    forn (i, 0, n)
        if (!col[i])
            dfs2(i);
    return f;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    edg.resize(m);
    forn (i, 0, m) {
        int t1, t2, w;
        cin >> t1 >> t2 >> w;
        t1--, t2--;
        edg[i] = {t1, t2, w};
    }
    /*check(2);
    return 0;*/
    int l = -1, r = 1e9;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    check(r);
    cout << r << " " << ans.size() << "\n";
    for (auto i : ans)
        cout << i << " ";
    return 0;
}
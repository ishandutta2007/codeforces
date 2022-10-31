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

void solve() {
    int n, m;
    cin >> n >> m;
    set <int> matching;
    vector <int> matching_ans;
    vector <vector <int>> gr(3 * n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, v--, u--;
        if (matching.find(v) == matching.end() && 
            matching.find(u) == matching.end()) {
            matching.insert(v), matching.insert(u);
            matching_ans.pb(i);
        }
        gr[v].pb(u), gr[u].pb(v);
    }
    if (sz(matching_ans) >= n) {
        cout << "Matching\n";
        forn (i, 0, n) 
            cout << matching_ans[i] + 1 << " ";
        cout << "\n";
        return;
    }
    vector <pii> ord;
    forn (i, 0, 3 * n) 
        ord.eb(sz(gr[i]), i);
    sort(all(ord));
    set <int> indset;
    vector <int> indset_ans;
    forn (i, 0, 3 * n) {
        bool ok = 1;
        for (int j : gr[ord[i].sc]) 
            if (indset.find(j) != indset.end())
                ok = 0;
        if (ok) {
            indset.insert(ord[i].sc);
            indset_ans.pb(ord[i].sc);
        }
    }
    if (sz(indset_ans) >= n) {
        cout << "IndSet\n";
        forn (i, 0, n) 
            cout << indset_ans[i] + 1 << " ";
        cout << "\n";
        return;
    }
    cout << "Impossible\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0) 
        solve();
    return 0;
}
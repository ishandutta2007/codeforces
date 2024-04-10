#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

vector <bool> used;
vector <vector <int>> gr;
vector <int> mt;

bool try_kuhn(int v) {
    if (used[v])
        return 0;
    used[v] = 1;
    for (int u : gr[v]) {
        if (mt[u] == -1 || try_kuhn(mt[u])) {
            mt[u] = v;
            return 1;
        }
    }
    return 0;
}

const int MAX_P = 5e3;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pii> a(n);
    forn (i, 0, n) 
        cin >> a[i].fs;
    forn (i, 0, n) 
        cin >> a[i].sc, a[i].sc--;
    int q;
    cin >> q;
    vector <bool> is_deleted(n);
    vector <int> b(q);
    forn (i, 0, q)
        cin >> b[i], b[i]--, is_deleted[b[i]] = 1;
    gr.resize(MAX_P);
    forn (i, 0, n) 
        if (!is_deleted[i])
            gr[a[i].fs].pb(a[i].sc);
    mt.resize(m, -1);
    vector <int> ans;
    int i = 0;
    while (!b.empty()) {
        while (true) { 
            used = vector <bool> (MAX_P);
            if (try_kuhn(i)) 
                i++;
            else 
                break;
        }
        ans.pb(i);
        gr[a[b.back()].fs].pb(a[b.back()].sc);
        b.pop_back();
    }
    reverse(all(ans));
    for (int j : ans)
        cout << j << "\n";
    return 0;
}
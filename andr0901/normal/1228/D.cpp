#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> gr(n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, v--, u--;
        gr[v].pb(u), gr[u].pb(v);
    }
    vector <int> colors(n, -1);
    vector <int> cnt_colors(3);
    vector <set <int>> connected(3);
    forn (v, 0, n) {
        vector <int> cnt_possible_colors(3);
        for (int u : gr[v]) 
            if (colors[u] != -1) 
                cnt_possible_colors[colors[u]]++;
        for (int i : {0, 1, 2}) {
            bool ok = true;
            forn (j, 0, 3) {
                if (i == j && cnt_possible_colors[j]) 
                    ok = false;
                if (i != j) {
                    if (cnt_possible_colors[j] != cnt_colors[j]) {
                        //cout << i << " " << j << "\n";
                        ok = false;
                    }
                } 
            }
            if (ok) {
                colors[v] = i;
                cnt_colors[i]++;
                break;
            }
        }  
        //cout << colors[v] << "\n\n";
        if (colors[v] == -1)
            return cout << -1, 0;
        for (int u : gr[v]) 
            connected[colors[v]].insert(u);
    }
    forn (i, 0, 3)
        if (!cnt_colors[i])
            return cout << -1, 0;
    forn (i, 0, n) 
        cout << colors[i] + 1 << " ";
    return 0;
}
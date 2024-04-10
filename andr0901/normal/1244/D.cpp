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

vector <vector <int>> gr, a;
vector <int> p;

void rearrange(int v, int par = -1, int i = 0) {
    p[i] = v;
    for (int u : gr[v])
        if (u != par)
            rearrange(u, v, i + 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    a.resize(3, vector <int> (n));
    forn (i, 0, 3)  
        forn (j, 0, n)
            cin >> a[i][j];
    gr.resize(n);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, v--, u--;
        gr[v].pb(u), gr[u].pb(v);
        if (gr[v].size() > 2 || gr[u].size() > 2)
            return cout << -1, 0;
    }
    p.resize(n);
    forn (i, 0, n) {
        if (sz(gr[i]) == 1) {
            rearrange(i);
            break;
        }
    }
    //forn (i, 0, n)  
       // cout << p[i] << " ";
    vector <vector <int>> new_a(3, vector <int> (n));
    forn (i, 0, 3)
        forn (j, 0, n)
            new_a[i][j] = a[i][p[j]];
    ll ans = 1e18;
    vector <int> best;
    forn (i, 0, 3) {
        forn (j, 0, 3) {
            if (i == j)
                continue;
            ll cnt = 0;
            vector <int> b(n);
            b[0] = i, b[1] = j;
            forn (k, 2, n) {
                if (k % 3 == 0)
                    b[k] = i;
                if (k % 3 == 1)
                    b[k] = j;
                if (k % 3 == 2)
                    b[k] = 3 - i - j;
            }
            forn (k, 0, n)
                cnt += new_a[b[k]][k];
            if (cnt < ans) {
                ans = cnt;
                best = b;
            }
        }
    }
    vector <int> rev(n);
    forn (i, 0, n)
        rev[p[i]] = i;
    cout << ans << "\n";
    forn (i, 0, n) 
        cout << best[rev[i]] + 1 << " ";
    return 0;
}
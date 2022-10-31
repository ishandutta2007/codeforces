//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
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

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    cin >> a;
    vector <pii> b(m);
    vector <bool> used(m);
    vector <vector <int>> adjacent(n);
    forn (i, 0, m) {
        cin >> b[i].fs >> b[i].sc, b[i].fs--, b[i].sc--;
        a[b[i].fs]--;
        a[b[i].sc]--;
        adjacent[b[i].fs].pb(i), adjacent[b[i].sc].pb(i);
    }
    vector <bool> free(n);
    deque <int> to_consider;
    forn (i, 0, n) {
        if (a[i] < 0)
            continue;
        for (int j : adjacent[i]) {
            if (!used[j]) {
                to_consider.pb(j);
                used[j] = true;
            }
        }
        free[i] = true;
    }
    vector <int> ans;
    while (!to_consider.empty()) {
        int i = to_consider.front();
        ans.pb(i + 1);
        auto [v, u] = b[i];
        to_consider.pop_front();
        a[v]++, a[u]++;
        if (a[v] >= 0 && !free[v]) {
            free[v] = true;
            for (int j : adjacent[v]) {
                if (!used[j]) {
                    to_consider.pb(j);
                    used[j] = true;
                }
            }
        }
        if (a[u] >= 0 && !free[u]) {
            free[u] = true;
            for (int j : adjacent[u]) {
                if (!used[j]) {
                    to_consider.pb(j);
                    used[j] = true;
                }
            }
        }
    }
    reverse(all(ans));
    if (sz(ans) < m) {
        cout << "DEAD";
    } else {
        cout << "ALIVE\n" << ans;
    }

    return 0;
}
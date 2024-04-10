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

vector <vector <int>> gr;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].pb(u), gr[u].pb(v);
    }
    vector <vector <int>> a(n);
    forn (i, 0, n) {
        int t;
        cin >> t;
        a[t - 1].pb(i);
    }
    vector <int> ans;
    vector <int> topics(n, -1);
    forn (i, 0, n) {
        for (int v : a[i]) {
            map <int, int> adjacent;
            for (int u : gr[v])
                if (topics[u] != -1)
                    adjacent[topics[u]]++;
            bool ok = true;
            forn (j, 0, i) {
                if (adjacent[j] == 0) {
                    ok = false;
                    break;
                }
            }
            if (adjacent[i] == 0 && ok)
                ans.pb(v + 1);
            else
                return cout << -1, 0;
            topics[v] = i;
        }
    }
    cout << ans;
    return 0;
}
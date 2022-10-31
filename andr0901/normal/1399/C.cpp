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
vector <int> used, mt;

bool try_kuhn(int v) {
    if (used[v])
        return 0;
    used[v] = 1;
    for (auto u : gr[v]) {
        if (mt[u] == -1 || try_kuhn(mt[u])) {
            mt[u] = v;
            return 1;
        }
    }
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    sort(all(a));
    int ans = 0;
    forn (w, 0, 2 * n + 1) {
        gr = vector <vector <int>> (n);
        forn (i, 0, n)
            forn (j, 0, n) {
                if (i != j && a[i] + a[j] == w) {
                    gr[i].pb(j), gr[j].pb(i);
                }
            }
        int cnt = 0;
        mt = vector <int> (n, -1);
        forn (i, 0, n) {
            used = vector <int> (n);
            if (try_kuhn(i))
                cnt++;
        }
        chkmax(ans, cnt);
    }
    cout << ans / 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}
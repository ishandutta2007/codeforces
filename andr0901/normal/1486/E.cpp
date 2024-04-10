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

constexpr int M = 51, INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> gr(n);
    forn (i, 0, m) {
        int v, u, w;
        cin >> v >> u >> w, --v, --u;
        gr[v].eb(u, w), gr[u].eb(v, w);
    }
    vector<vector<int>> dst(n, vector<int> (M, INF));
    dst[0][0] = 0;
    set<tuple<int, int, int>> s = {{0, 0, 0}};
    while (!s.empty()) {
        auto [d, v, carry] = *s.begin();
        s.erase(s.begin());
        for (auto [u, w] : gr[v]) {
            int nxt_carry = (carry == 0 ? w : 0);
            int nxt_dst = d + w * w + 2 * carry * w;
            if (nxt_dst < dst[u][nxt_carry]) {
                s.erase({dst[u][nxt_carry], u, nxt_carry});
                dst[u][nxt_carry] = nxt_dst;
                s.insert({dst[u][nxt_carry], u, nxt_carry});
            }
        }
    }
    forn (i, 0, n)
        cout << (dst[i][0] == INF ? -1 : dst[i][0]) << " ";
    return 0;
}
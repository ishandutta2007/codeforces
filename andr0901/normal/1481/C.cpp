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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m);
    cin >> a >> b >> c;
    forn (i, 0, n) {
        --a[i];
        --b[i];
    }
    forn (i, 0, m) {
        --c[i];
    }
    vector<vector<int>> done(n), to_be_done(n);
    int lst = -1;
    forn (i, 0, n) {
        if (a[i] == b[i]) {
            done[a[i]].pb(i);
        } else {
            to_be_done[b[i]].pb(i);
        }
    }
    vector<int> ans(m);
    for (int i = m - 1; i >= 0; --i) {
        int cur = c[i];
        if (to_be_done[cur].empty()) {
            if (done[cur].empty()) {
                if (lst == -1) {
                    cout << "NO\n";
                    return;
                }
                ans[i] = lst;
            } else {
                ans[i] = done[cur].back();
                lst = ans[i];
            }
        } else {
            ans[i] = to_be_done[cur].back();
            lst = ans[i];
            to_be_done[cur].pop_back();
        }
    }
    forn (i, 0, n)
        if (!to_be_done[i].empty()) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
    for (int i : ans)
        cout << i + 1 << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}
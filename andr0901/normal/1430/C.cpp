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
    int n;
    cin >> n;
    /*vector <vector <int>> a(2);
    forn (i, 1, n + 1)
        a[i % 2].pb(i);
    vector <pii> ans;
    forn (i, 0, n - 1) {
        bool done = false;
        forn (j, 0, 2) {
            if (a[j].size() >= 2) {
                int v = a[j].back();
                a[j].pop_back();
                int u = a[j].back();
                a[j].pop_back();
                int s = (v + u + 1) / 2;
                ans.eb(v, u);
                a[s % 2].pb(s);
                done = true;
                break;
            }
        }
        if (!done) {
            int v = a[0].back(), u = a[1].back();
            a[0].pop_back(), a[1].pop_back();
            int s = (v + u + 1) / 2;
            ans.eb(v, u);
            a[s % 2].pb(s);
        }
    }
    if (a[0].empty())
        cout << a[1][0];
    else
        cout << a[0][0];
    cout << "\n";*/
    vector <pii> ans;
    vector <int> a(n);
    iota(all(a), 1);
    while (a.size() >= 2) {
        int v = a.back();
        a.pop_back();
        int u = a.back();
        a.pop_back();
        int s = (v + u + 1) / 2;
        ans.eb(v, u);
        a.pb(s);
    }
    cout << a[0] << "\n";
    for (auto i : ans)
        cout << i.fs << " " << i.sc << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}
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
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    int good_pref = -1, good_suf = n;
    vector <vector <int>> ans;
    auto perform = [&](vector <pii> segments) {
        for (auto i : segments)
            cerr << i.fs << " " << i.sc << "\n";
        cerr << "\n";
        ans.pb({});
        vector <vector <int>> d;
        for (auto [l, r] : segments) {
            d.pb({});
            forn (i, l, r + 1)
                d.back().pb(a[i]);
            if (r - l + 1 > 0)
                ans.back().pb(r - l + 1);
        }
        reverse(all(d));
        a.clear();
        forn (i, 0, sz(d))
            for (int x : d[i])
                a.pb(x);
        if (ans.back().size() == 1)
            ans.pop_back();
        cerr << a << "\n\n";
    };
    for (int i = 1, j = n; i < j; ++i, --j) {
        int pos_i, pos_j;
        forn (k, 0, n) {
            if (a[k] == i)
                pos_i = k;
            if (a[k] == j)
                pos_j = k;
        }
        if (pos_i < pos_j) {
            perform({{0, good_pref},
                     {good_pref + 1, pos_i},
                     {pos_i + 1, pos_j - 1},
                     {pos_j, good_suf - 1},
                     {good_suf, n - 1}
                      });
            vector <pii> to_perform;
            to_perform.pb({0, n - good_suf - 1});
            forn (i, n - good_suf, n - good_pref - 1)
                to_perform.pb({i, i});
            to_perform.pb({n - good_pref - 1, n - 1});
            perform(to_perform);
        } else {
            perform({{0, good_pref},
                     {good_pref + 1, pos_j},
                     {pos_j + 1, pos_i - 1},
                     {pos_i, good_suf - 1},
                     {good_suf, n - 1}
                      });
            perform({{0, n - good_suf - 1},
                     {n - good_suf, n - good_pref - 2},
                     {n - good_pref - 1, n - 1}
                      });
        }
        ++good_pref, --good_suf;
        cerr << a << "\n";
    }
    cout << sz(ans) << "\n";
    for (auto i : ans)
        cout << sz(i) << " " << i << "\n";
    return 0;
}
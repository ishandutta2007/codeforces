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

constexpr int INF = 1e9 + 5;

void solve() {
    int n;
    cin >> n;
    vector<pii> segments(n);
    vector<int> l(n), r(n);
    forn (i, 0, n) {
        cin >> l[i] >> r[i];
        segments[i] = {l[i], r[i]};
    }
    sort(all(l)), sort(all(r));
    auto count_l = [&](int L, int R) {
        return lower_bound(all(l), R + 1) - lower_bound(all(l), L);
    };
    auto count_r = [&](int L, int R) {
        return lower_bound(all(r), R + 1) - lower_bound(all(r), L);
    };
    int ans = 1e9;
    forn (i, 0, n)
        chkmin(ans, count_r(-INF, segments[i].fs - 1) + count_l(segments[i].sc + 1, INF));
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}
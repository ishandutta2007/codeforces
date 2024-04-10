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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    auto f = [&](int m) -> __int128_t {
        long long damage = 1LL * (m + 1) * a;
        int open = min(m, c / d);
        __int128_t healed = static_cast<__int128_t>(b) * d * open * (open + 1) / 2;
        int closed = max(0, m - open);
        // cerr << open << " " << closed << " " << healed << ": ";
        healed += 1LL * closed * b * c;
        return damage - healed;
    };
    int l = 0, r = 1e6 + 10;
    while (r - l > 2) {
        int m_1 = l + (r - l) / 3, m_2 = l + 2 * (r - l) / 3;
        if (f(m_1) >= f(m_2))
            r = m_2;
        else
            l = m_1; 
    }
    long long ans = -1;
    forn (i, l, r + 1)
        chkmax(ans, f(i));
    if (l > 1e6)
        cout << -1;
    else
        cout << ans;
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
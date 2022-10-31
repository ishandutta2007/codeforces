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
    vector<int> a(n);
    cin >> a;
    map<int, int> cnt;
    forn (i, 0, n)  
        cnt[a[i]]++;
    vector<int> cnts;
    for (auto [x, c] : cnt)
        cnts.pb(c);
    auto f = [&](int m) {
        long long s = 0;
        forn (i, 0, sz(cnts))
            if (cnts[i] < m)
                s += cnts[i];
            else
                s += cnts[i] - m;
        return s;
    };
    int ans = f(0);
    vector<int> unique_cnts = cnts;
    unique_cnts.erase(unique(all(unique_cnts)), unique_cnts.end());
    for (int c : unique_cnts)
        chkmin(ans, f(c));
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
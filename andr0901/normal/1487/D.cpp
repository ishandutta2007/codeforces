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

#define int long long

vector<int> possible;

void solve() {
    int n;
    cin >> n;
    cout << lower_bound(all(possible), n + 1) - possible.begin() << "\n";
}

constexpr int N = 1e5;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    for (int i = 3; i < N; i += 2) {
        int a = i;
        int b = 1LL * a * a / 2;
        int c = b + 1;
        possible.pb(c);
        if (i < 10)
            cerr << a << " " << b << " " << c << "\n";
    }
    
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}
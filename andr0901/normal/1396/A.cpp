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

const int INF = 5;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    if (n == 1) {
        cout << "1 1\n" << -a[0] << "\n";
        forn (i, 0, 2)
            cout << "1 1\n0\n";
        return;
    }
    cout << "1 1\n" << -a[0] << "\n";
    a[0] = 0;
    cout << "2 " << n << "\n";
    forn (i, 1, n) {
        int d = INF / (n - 1) * (n - 1);
        a[i] += d;
        int r = a[i] % n;
        a[i] += r * (n - 1);
        d += r * (n - 1);
        cout << d << " ";
    }
    cout << "\n";
    cout << "1 " << n << "\n";
    forn (i, 0, n)
        cout << -a[i] << " ";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t --> 0)
        solve();
    return 0;
}
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
    vector <int> a(n);
    cin >> a;
    long long s = 0;
    for (int i = 0; i < n; i += 2)
        s += a[i];
    cerr << s << "\n";
    long long ans = s, odd_mx = 0, even_mx = 0, odd_s = 0, even_s = 0;
    forn (i, 0, n) {
        if (i % 2 == 0) {
            s -= a[i];
            even_s += a[i];
        }
        if (i % 2) {
            odd_s += a[i];
        }
        if (i % 2 == 0)
            chkmax(even_mx, even_s - odd_s);
        else
            chkmax(odd_mx, even_s - odd_s);
        if (i % 2 == 0)
            chkmax(ans, odd_s + even_mx + s);
        else
            chkmax(ans, odd_s + odd_mx + s);
    }
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
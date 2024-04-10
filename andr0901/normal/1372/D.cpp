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

#define int long long

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    if (n == 1) {
        cout << a[0];
        return 0;
    }
    forn (i, 0, n)
        a.pb(a[i]);
    vector <int> s(2);
    forn (i, 2, n - 1)
        s[i % 2] += a[i];
    int ans = 0, j = n - 1;
    forn (i, 0, n) {
        chkmax(ans, a[i] + a[i + 1] + s[(i % 2) ^ 1]);
        s[i % 2] -= a[i + 2];
        s[i % 2] += a[j++];
        cerr << s << "\n";
    }
    cout << ans;
    return 0;
}
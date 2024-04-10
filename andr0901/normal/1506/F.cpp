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

int get_even(int x, int y) {
    if (x > y)
        return 0;
    if (x == y)
        return x % 2 == 0 ? 1 : 0;
    int l = (x + 1) / 2, r = y / 2;
    return r - l + 1;
}

int get_odd(int x, int y) {
    if (x > y)
        return 0;
    return y - x + 1 - get_even(x, y);
}
 
void solve() {
    int n;
    cin >> n;
    vector<pii> a(n);
    forn (i, 0, n)
        cin >> a[i].fs;
    forn (i, 0, n)
        cin >> a[i].sc;
    a.pb({1, 1});
    sort(all(a));
    long long ans = 0;
    forn (i, 0, n) {
        if ((a[i].fs + a[i].sc) % 2 == 0) {
            if (a[i + 1].sc - a[i].sc == a[i + 1].fs - a[i].fs) {
                ans += a[i + 1].sc - a[i].sc;
                continue;
            }
        }
        if (a[i].fs + a[i].sc & 1) {
            int dy = a[i + 1].sc - a[i].sc;
            a[i].fs += dy;
            a[i].sc = a[i + 1].sc;
        } else {
            a[i].fs++;
            int dy = a[i + 1].sc - a[i].sc;
            a[i].fs += dy;
            a[i].sc = a[i + 1].sc;
        }
        cerr << a[i].fs << " " << a[i].sc << "  ";
        int even = get_even(a[i].fs, a[i + 1].fs - 1);
        int odd = get_odd(a[i].fs, a[i + 1].fs - 1);
        cerr << a[i + 1].fs << " " << a[i + 1].sc << "  ";
        cerr << even << " " << odd << "\n";
        if (a[i].sc % 2 == 0) {
            ans += odd;
        } else {
            ans += even;
        }
        cerr << ans << "\n\n";
    }
    cerr << "\n";
    cout << ans << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}
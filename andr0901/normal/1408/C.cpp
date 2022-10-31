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
    int n, len;
    cin >> n >> len;
    vector <int> a(n);
    cin >> a;
    auto get_left = [&](double t) {
        double v = 1;
        double x = 0;
        forn (i, 0, n) {
            double needed = (1.0 * a[i] - x) / v;
            if (needed > t)
                break;
            t -= needed;
            x = a[i];
            ++v;
        }
        return x + v * t;
    };
    auto get_right = [&](double t) {
        double v = 1;
        double x = len;
        for (int i = n - 1; i >= 0; --i) {
            double needed = (1.0 * x - a[i]) / v;
            if (needed > t)
                break;
            t -= needed;
            x = a[i];
            ++v;
        }
        return x - v * t;
    };
    cerr << get_left(3) << " " << get_right(3) << "\n";;
    double l = 0, r = 1e9;
    forn (i, 0, 120) {
        double m = (l + r) / 2;
        if (get_left(m) >= get_right(m))
            r = m;
        else
            l = m;
    }
    cout << fixed << setprecision(10) << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}
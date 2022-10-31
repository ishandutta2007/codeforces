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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> b(n);
    cin >> b;
    sort(all(a));
    sort(all(b));
    vector<int> pr_a(n + 1);
    forn (i, 0, n) {
        pr_a[i + 1] = pr_a[i] + a[i];
    }
    vector<int> pr_b(n + 1);
    forn (i, 0, n) {
        pr_b[i + 1] = pr_b[i] + b[i];
    }

    auto check = [&](int m) {
        int needed = (n + m) - (n + m) / 4;
        int sum_a, sum_b;
        if (m >= needed) {
            return true;
        } else {
            int diff = needed - m;
            sum_a = 100 * m +
                pr_a[n] - pr_a[n - diff];
        
            if (n >= needed) {
                sum_b = pr_b[n] - pr_b[n - needed];
            } else {
                sum_b = pr_b[n];
            }
        }
        cerr << n + m << " " << needed << "\n";
        cerr << sum_a << " " << sum_b << "\n";
        return sum_a >= sum_b;
    };

    check(3);
    check(4);
    cerr << "---\n";

    int l = -1, r = 1e9;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}
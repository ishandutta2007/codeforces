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
    int init_a, init_b, init_x, init_y, init_n;
    cin >> init_a >> init_b >> init_x >> init_y >> init_n;
    long long ans = 1e18; {
        int a = init_a, b = init_b, x = init_x, y = init_y, n = init_n;
        int t = min(a - x, n);
        a -= t, n -= t;
        t = min(b - y, n);
        b -= t, n -= t;
        chkmin(ans, 1LL * a * b);
    }
    swap(init_a, init_b), swap(init_x, init_y); {
        int a = init_a, b = init_b, x = init_x, y = init_y, n = init_n;
        int t = min(a - x, n);
        a -= t, n -= t;
        t = min(b - y, n);
        b -= t, n -= t;
        chkmin(ans, 1LL * a * b);
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
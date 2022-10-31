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

int count(int x) {
    cerr << x << " ";
    int ans = 0;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            while (x % i == 0) {
                ++ans;
                x /= i;
            }
        }
    }
    if (x > 1) {
        ++ans;
    }
    cerr << " " << ans << "\n";
    return ans;
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    int mn;
    if (a == b) {
        mn = 2;
    } else if (a == gcd(a, b) || b == gcd(a, b)) {
        mn = 1;
    } else {
        mn = 2;
    }
    int mx = count(a) + count(b);
    cout << (mn <= k && k <= mx ? "YES" : "NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}
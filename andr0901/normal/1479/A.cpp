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

constexpr int INF = 1e8;

void solve() {
    int n;
    cin >> n;
    auto ask = [&](int m) {
        if (m == -1 || m == n)
            return INF;
        cout << "? " << m + 1 << endl;
        int ans;
        cin >> ans;
        return ans;
    };
    auto check = [&](int m) {
        int l = ask(m);
        int r = ask(m + 1);
        return r - l > 0;
    };
    int l = -1, r = n - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m;
    }
    cout << "! " << r + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t --> 0)
        solve();
    return 0;
}
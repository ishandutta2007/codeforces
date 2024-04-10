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
    if (n <= 30) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (n - 30 == 6)
        cout << "5 6 10 15";
    else if (n - 30 == 10)
        cout << "6 10 15 9";
    else if (n - 30 == 14)
        cout << "6 7 10 21";
    else
        cout << "6 10 14 " << n - 30;
    cout << "\n";
}

// 2 * 3 + 2 * 5 + 3 * 5 = 6 + 10 + 15 = 16 + 15 = 31

// 2 * 3 + 2 * 5 + 2 * 7 = 2 (3 + 5 + 7) = 2 * 15 = 30

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}
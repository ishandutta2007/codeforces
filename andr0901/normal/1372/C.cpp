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
    forn (i, 0, n)
        --a[i];
    int correct = 0;
    forn (i, 0, n)
        if (a[i] == i)
            correct++;
    if (correct == n) {
        cout << "0\n";
        return;
    }
    int cnt = 0;
    int l = -1, r = -1;
    forn (i, 0, n) {
        if (i != a[i]) {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (i != a[i]) {
            r = i;
            break;
        }
    }
    if (l == -1) {
        cout << "1\n";
        return;
    }
    forn (i, l, r + 1)
        if (i == a[i]) {
            cout << "2\n";
            return;
        }
    cout << "1\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}
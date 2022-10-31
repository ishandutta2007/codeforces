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
    vector<int> a(n);
    cin >> a;
    set<int> not_used;
    forn (i, 0, n)
        not_used.insert(i + 1);
    vector<int> pinned(n);
    pinned[0] = a[0];
    not_used.erase(a[0]);
    forn (i, 1, sz(a)) {
        if (a[i] != a[i - 1]) {
            pinned[i] = a[i];
            not_used.erase(a[i]);
        }
    }
    auto copy_not_used = not_used;
    forn (i, 0, n) {
        if (pinned[i]) {
            cout << pinned[i] << " ";
        } else {
            cout << *not_used.begin() << " ";
            not_used.erase(not_used.begin());
        }
    }
    cout << "\n";
    not_used = copy_not_used;
    forn (i, 0, n) {
        if (pinned[i]) {
            cout << pinned[i] << " ";
        } else {
            cout << *--not_used.lower_bound(a[i]) << " ";
            not_used.erase(*--not_used.lower_bound(a[i]));
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}
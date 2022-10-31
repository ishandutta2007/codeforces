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
    vector <int> ans;
    auto shift = [&](int i) {
        ans.pb(i + 1);
        swap(a[i], a[i + 1]);
        swap(a[i], a[i + 2]);
    };
    forn (i, 0, n - 2) {
        int mn = 1e9, k = -1;
        forn (j, i, n) {
            if (a[j] < mn) {
                mn = a[j];
                k = j;
            }
        }
        if (a[i] == mn)
            continue;
        while (k >= i + 2) {
            shift(k - 2);
            k -= 2;
        }
        if (k == i)
            continue;
        shift(i), shift(i);
        cerr << a << "\n";
    }
    if (a[n - 3] == a[n - 1])
        shift(n - 3);
    if (a[n - 2] > a[n - 1]) {
        int same = -1;
        forn (i, 1, n)
            if (a[i] == a[i - 1])
                same = i;
        if (same == -1) {
            cout << "-1\n";
            return;
        }
        int k = n - 2;
        while (k > same) {
            shift(k - 2);
            k -= 2;
        }
        cerr << a << "\n";
        if (k == same) {
            shift(k - 1);
            ++k;
        } else {
            shift(k);
            shift(k + 1);
            shift(k + 1);
            k += 3;
        }
        while (k < n - 2) {
            shift(k);
            shift(k);
            k += 2;
        }
        cerr << a << "\n";
    }
    assert(sz(ans) <= n * n);
    if (sz(ans) > n * n) {
        cout << "-1\n";
        return;
    }
    cout << sz(ans) << "\n" << ans << "\n";;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}
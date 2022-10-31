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

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    cin >> a >> b;
    vector<int> left(n), right(n);
    forn (i, 0, n) {
        left[i] = (i == 0 ? a[i] * b[i] : a[i] * b[i] + left[i - 1]);
    }
    for (int i = n - 1; i >= 0; --i) {
        right[i] = (i == n - 1 ? a[i] * b[i] : a[i] * b[i] + right[i + 1]);
    }
    int ans = left[n - 1];
    forn (i, 0, n - 1) {
        int s = 0;
        for (int l = i, r = i + 1; 0 <= l && r < n; --l, ++r) {
            s += a[l] * b[r];
            s += b[l] * a[r];
            int cur = s;
            cur += (l - 1 >= 0 ? left[l - 1] : 0);
            cur += (r + 1 < n ? right[r + 1] : 0);
            cerr << i << " " << l << " " << r << " " << s << " " << cur << "\n";
            chkmax(ans, cur);
        }
    }
    forn (i, 0, n) {
        int s = a[i] * b[i];
        for (int l = i - 1, r = i + 1; 0 <= l && r < n; --l, ++r) {
            s += a[l] * b[r];
            s += a[r] * b[l];
            int cur = s;
            cur += (l - 1 >= 0 ? left[l - 1] : 0);
            cur += (r + 1 < n ? right[r + 1] : 0);
            chkmax(ans, cur);
        }
    }
    cout << ans << "\n";
    return 0;
}
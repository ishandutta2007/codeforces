#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << "\n"
#define test(args...) info(), kout("[" + string(#args) + "]", args)
#define printv(a) {\
    info();\
    for (auto i : a) cerr << i << ' ';\
    cerr << endl;\
}
void kout() {cerr << endl;}
template <class T, class ...U>
void kout(T a, U ...b) {cerr << a << ' ', kout(b...);}
template <typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a) {
    return o << a.X << ' ' << a.Y;
}
template <typename A>
ostream& operator << (ostream& o, vector <A> a) {
    for (auto i : a) o << i << ' ';
    return o;
}
const int mod = 1e9 + 7, abc = 864197532, Doludu = 123, N = 300001, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <lli> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    lli ans = 0;
    for (int i = 0; i < n; ++i) {
        lli cur = 0;
        for (int d = 1; ; ++d) {
            int ii = i - d, jj = i + d;
            if (ii < 0 || jj >= n) break;
            cur += (a[jj] - a[ii]) * b[ii] + (a[ii] - a[jj]) * b[jj];
            ans = max(ans, cur);
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        lli cur = (a[i + 1] - a[i]) * b[i] + (a[i] - a[i + 1]) * b[i + 1];
        ans = max(ans, cur);
        for (int d = 1; ; ++d) {
            int ii = i - d, jj = i + 1 + d;
            if (ii < 0 || jj >= n) break;
            cur += (a[jj] - a[ii]) * b[ii] + (a[ii] - a[jj]) * b[jj];
            ans = max(ans, cur);
        }
    }
    for (int i = 0; i < n; ++i) ans += a[i] * b[i];
    cout << ans << endl;
}
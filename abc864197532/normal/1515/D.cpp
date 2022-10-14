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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
#define test(args...) info(), abc("[" + string(#args) + "]", args)
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
const int mod = 1e9 + 7, N = 400001, logN = 20, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector <int> cnt(n, 0);
        for (int i = 0, x; i < l; ++i) cin >> x, cnt[--x]++;
        for (int i = 0, x; i < r; ++i) cin >> x, cnt[--x]--;
        int neg = 0, pos = 0, neg1 = 0, pos1 = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] < 0) neg -= cnt[i], neg1 += (-cnt[i]) / 2;
            else pos += cnt[i], pos1 += cnt[i] / 2;
        }
        int ans = 1 << 30;
        for (int i = 0; i <= pos1; ++i) {
            int tmp = pos - i * 2;
            if (tmp >= neg) ans = min(ans, i + tmp);
            else {
                int best = (neg - tmp + 1) / 2;
                best = min(best, neg1);
                ans = min(ans, i + best + max(tmp, neg - 2 * best));
            }
        }
        cout << ans << endl;
    }
}
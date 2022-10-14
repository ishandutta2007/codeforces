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
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1 << 18, logN = 18, G = 3;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vv <int> a(2, n);
        for (int i = 0; i < 2; ++i) for (int j = 0; j < n; ++j)
            cin >> a[i][j];
        a[0][0] = -87;
        int ans = 1 << 30;
        // ->
        // <-
        {
            vector <int> suf1(n + 1), suf2(n + 1);
            for (int i = n - 1; ~i; --i) {
                suf1[i] = max(suf1[i + 1], a[0][i] + 1 - i);
                suf2[i] = max(suf2[i + 1], a[1][i] + 1 + i);
            }
            int now = 0, cur = 0;
            for (int i = 0; i < n; i += 2) {
                if (i >= 2) {
                    cur = max(cur, a[0][i - 2] + 1 - now);
                    cur = max(cur, a[1][i - 2] + 1 - (now + 1));
                    cur = max(cur, a[1][i - 1] + 1 - (now + 2));
                    cur = max(cur, a[0][i - 1] + 1 - (now + 3));
                    now += 4;
                }
                int now2 = cur;
                now2 = max(now2, suf1[i] - now + i);
                now2 = max(now2, suf2[i] - (n + n - 1) - i);
                ans = min(ans, now2);
            }
        }
        // <-
        // ->
        {
            vector <int> suf1(n + 1), suf2(n + 1);
            for (int i = n - 1; ~i; --i) {
                suf1[i] = max(suf1[i + 1], a[0][i] + 1 + i);
                suf2[i] = max(suf2[i + 1], a[1][i] + 1 - i);
            }
            int now = 2, cur = a[1][0];
            for (int i = 1; i < n; i += 2) {
                if (i >= 2) {
                    cur = max(cur, a[1][i - 2] + 1 - now);
                    cur = max(cur, a[0][i - 2] + 1 - (now + 1));
                    cur = max(cur, a[0][i - 1] + 1 - (now + 2));
                    cur = max(cur, a[1][i - 1] + 1 - (now + 3));
                    now += 4;
                }
                int now2 = cur;
                now2 = max(now2, suf1[i] - (n + n - 1) - i);
                now2 = max(now2, suf2[i] - now + i);
                ans = min(ans, now2);
            }
        }
        ans = max(ans, 0);
        cout << ans + 2 * n - 1 << '\n';
    }
}
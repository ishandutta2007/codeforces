#include <bits/stdc++.h>
using namespace std;
#define lli int_fast64_t
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
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 100005, logN = 18, C = 512;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <lli> a;
        {
            lli pre, x; cin >> pre;
            for (int i = 1; i < n; ++i) {
                cin >> x;
                a.pb(abs(x - pre));
                pre = x;
            }
        }
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        vv <lli> ST(n - 1, logN, 0);
        for (int i = 0; i < n - 1; ++i)
            ST[i][0] = a[i];
        for (int j = 1; j < logN; ++j) {
            for (int i = 0; i + (1 << j) <= n - 1; ++i) {
                ST[i][j] = __gcd(ST[i][j - 1], ST[i + (1 << j - 1)][j - 1]);
            }
        }
        auto query = [&](int l, int r) {
            int g = __lg(r - l);
            return __gcd(ST[l][g], ST[r - (1 << g)][g]);
        };
        int ans = 1;
        for (int i = 0, j = 0; i < n - 1; ++i) {
            j = max(j, i);
            while (j < n - 1 && query(i, j + 1) != 1)
                j++;
            if (i == j || query(i, j) != 1)
                ans = max(ans, j - i + 1);
        }
        cout << ans << '\n';
    }
}
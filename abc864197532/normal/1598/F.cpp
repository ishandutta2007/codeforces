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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
template <typename T> struct vvvv : vector <vvv <T>> {
    vvvv(int n, int m, int k, int t, T v) : vector <vvv <T>> (n, vvv <T>(m, k, t, v)) {}
    vvvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 400087, logN = 20, K = 1500;

int m1[20][N + N];

int main () {
    owo;
    int n;
    cin >> n;
    vector <string> s(n);
    vector <int> d(n), mn(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (char c : s[i]) {
            d[i] += c == '(' ? 1 : -1;
            mn[i] = min(mn[i], d[i]);
            if (mn[i] == d[i])
                m1[i][d[i] + N]++;
        }
    }
    vv <int> dp(1 << n, 2, -1 << 30);
    dp[0][0] = 0;
    for (int s = 1; s < 1 << n; ++s) {
        int all_d = 0;
        for (int i = 0; i < n; ++i) if (s >> i & 1) {
            all_d += d[i];
        }
        for (int i = 0; i < n; ++i) if (s >> i & 1) {
            all_d -= d[i];
            dp[s][1] = max(dp[s][1], dp[s ^ (1 << i)][1]);
            if (all_d + mn[i] < 0) {
                dp[s][1] = max(dp[s][1], dp[s ^ (1 << i)][0] + m1[i][-all_d + N]);
            } else {
                dp[s][0] = max(dp[s][0], dp[s ^ (1 << i)][0] + m1[i][-all_d + N]);
            }
            all_d += d[i];
        }
    }
    cout << max(dp[(1 << n) - 1][0], dp[(1 << n) - 1][1]) << endl;
}
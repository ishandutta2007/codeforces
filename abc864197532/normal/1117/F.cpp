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
const int mod = 998244353, N = 300001, logN = 20, K = 15;

int main () {
    owo;
    int n, p;
    string s;
    cin >> n >> p >> s;
    vv <int> dead(p, p, false);
    for (int i = 0; i < p; ++i) for (int j = 0; j < p; ++j) {
        cin >> dead[i][j];
    }
    vector <bool> bad(1 << p, false);
    for (int c1 = 0; c1 < p; ++c1) for (int c2 = 0; c2 < p; ++c2) if (!dead[c1][c2]) {
        vector <bool> msk(1 << p, false);
        int now = -1, bit = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] - 'a' == c2) {
                if (~now) {
                    msk[bit] = true;
                    now = -1;
                }
            }
            bit |= 1 << s[i] - 'a';
            if (s[i] - 'a' == c1) {
                now = i;
                bit = 0;
            }
        }
        for (int i = 0; i < p; ++i) for (int s = 0; s < 1 << p; ++s) if (~s >> i & 1) {
            if (msk[s]) 
                msk[s ^ (1 << i)] = true;
        }
        for (int s = 0; s < 1 << p; ++s) if (msk[s]) {
            int now = s ^ ((1 << p) - 1);
            bad[now | (1 << c1) | (1 << c2)] = true;
        }
    }
    vector <int> cnt(p, 0);
    for (char c : s)
        cnt[c - 'a']++;
    int ans = n;
    vector <bool> dp(1 << p, 0);
    dp[(1 << p) - 1] = true;
    for (int s = (1 << p) - 1; ~s; --s) if (!bad[s] && dp[s]) {
        int cur = 0;
        for (int i = 0; i < p; ++i) if (s >> i & 1)
            cur += cnt[i];
        ans = min(ans, cur);
        for (int i = 0; i < p; ++i) if (s >> i & 1) {
            dp[s ^ (1 << i)] = true;
        }
    }
    cout << ans << endl;
}
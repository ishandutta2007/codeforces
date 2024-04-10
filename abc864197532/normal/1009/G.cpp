/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
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
const int mod = 998244353, N = 1000001, logN = 20, K = 111;

int main () {
    owo;
    vector <int> cnt(6, 0);
    string s;
    cin >> s;
    int n = s.length();
    for (char c : s) 
        cnt[c - 'a']++;
    vector <int> msk(n, 63), cnt2(64, 0);
    int m;
    cin >> m;
    for (int i = 0, p; i < m; ++i) {
        cin >> p >> s, --p;
        msk[p] = 0;
        for (char c : s)
            msk[p] |= 1 << c - 'a';
    }
    for (int i = 0; i < n; ++i)
        cnt2[msk[i]]++;
    string ans;
    for (int i = 0; i < n; ++i) {
        bool is = true;
        cnt2[msk[i]]--;
        for (int c = 0; c < 6; ++c) if (msk[i] >> c & 1 && cnt[c]) {
            cnt[c]--;
            bool ok = true;
            vector <int> dp = cnt2;
            for (int i = 0; i < 6; ++i) for (int s = 0; s < 1 << 6; ++s) if (s >> i & 1) {
                dp[s] += dp[s ^ (1 << i)];
            }
            for (int s = 0; s < 1 << 6; ++s) {
                int cur = 0;
                for (int i = 0; i < 6; ++i) if (s >> i & 1) {
                    cur += cnt[i];
                }
                ok &= dp[s] <= cur;
            }
            if (ok) {
                ans += c + 'a';
                is = false;
                break;
            }
            cnt[c]++;
        }
        if (is)
            return cout << "Impossible\n", 0;
    }
    cout << ans << endl;
}
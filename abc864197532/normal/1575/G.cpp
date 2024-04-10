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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 100087, logN = 20, K = 111;

vector <int> f[N];

int main () {
    owo;
    for (int i = 1; i < N; ++i) for (int j = i; j < N; j += i) {
        f[j].pb(i);
    }
    int n;
    cin >> n;
    vector <int> a(n + 1), phi(N);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < N; ++i) {
        int x = i;
        phi[i] = i;
        for (int j = 2; j * j <= x; ++j) if (x % j == 0) {
            phi[i] -= phi[i] / j;
            while (x % j == 0) x /= j;
        }
        if (x > 1)
            phi[i] -= phi[i] / x;
    }
    vector <lli> cnt(N, 0), ans(n + 1, 0);
    for (int d = 1; d <= n; ++d) {
        for (int i = d; i <= n; i += d) {
            for (int j : f[a[i]]) {
                ans[d] += (cnt[j] * 2 + 1) * phi[j] % mod;
                cnt[j]++;
                if (ans[d] >= mod)
                    ans[d] -= mod;
            }
        }
        for (int i = d; i <= n; i += d) {
            for (int j : f[a[i]]) {
                cnt[j]--;
            }
        }
    }
    lli tans = 0;
    for (int i = n; i > 0; --i) {
        for (int j = i + i; j <= n; j += i) {
            ans[i] -= ans[j];
            if (ans[i] < 0)
                ans[i] += mod;
        }
        (tans += ans[i] * i) %= mod;
    }
    cout << tans << endl;
}
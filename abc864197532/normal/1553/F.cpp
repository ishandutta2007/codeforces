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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 300005, logN = 20, K = 550;


struct BIT {
    lli bit[N];

    BIT () {
        for (int i = 0; i < N; ++i) bit[i] = 0;
    }

    void add(int p, int v) {
        for (int i = p; i < N; i += i & (-i)) bit[i] += v;
    }

    lli query(int p) {
        lli ans = 0;
        for (int i = p; i > 0; i -= i & (-i)) ans += bit[i];
        return ans;
    }

    lli query(int l, int r) { // [l, r)
        return query(r - 1) - query(l - 1);
    }
} BIT1, BIT2;

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> a(n), cnt(K, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <lli> ans = {0};
    if (a[0] < K) cnt[a[0]]++;
    else BIT1.add(a[0], a[0]);
    BIT2.add(a[0], 1);
    lli pre = a[0];
    for (int i = 1; i < n; ++i) {
        lli res = pre + 1ll * a[i] * i;
        for (int j = 1; j < K; ++j) {
            res -= 1ll * cnt[j] * (a[i] / j) * j;
        }
        for (int ans = 1; ; ++ans) {
            int r = a[i] / ans + 1, l = a[i] / (ans + 1) + 1;
            if (r <= K) break;
            res -= BIT1.query(l, r) * ans;
        }
        for (int ans = 1; a[i] * ans < N; ++ans) {
            int l = a[i] * ans, r = a[i] * (ans + 1);
            r = min(r, N);
            res -= BIT2.query(l, r) * ans * a[i];
        }
        ans.pb(ans.back() + res);
        if (a[i] < K) cnt[a[i]]++;
        else BIT1.add(a[i], a[i]);
        BIT2.add(a[i], 1);
        pre += a[i];
    }
    printv(all(ans));
}
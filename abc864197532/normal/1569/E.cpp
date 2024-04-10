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
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 100001, logN = 20, K = 80000;

int rk[6] = {1, 2, 3, 5, 9, 17};
int cnt[6] = {1, 1, 2, 4, 8, 16};

lli pw[100];

int main () {
    owo;
    int k, A, hsh;
    cin >> k >> A >> hsh;
    pw[0] = 1;
    for (int i = 1; i < 100; ++i) {
        pw[i] = pw[i - 1] * A % mod;
    }
    for (int i = 0; i <= k; ++i) {
        hsh -= pw[rk[i]] * cnt[i] % mod;
        if (hsh < 0) hsh += mod;
    }
    int m = 1 << k - 1;
    map <int, vector <int>> m1[m];
    for (int s = 0; s < 1 << m - 1; ++s) {
        vector <int> res(m, -1);
        int val = 0;
        vector <int> now(m);
        iota(all(now), 0);
        int pt = 0, r = k;
        while (now.size() > 1) {
            vector <int> nxt;
            for (int i = 0; i < now.size(); i += 2) {
                if (s >> pt & 1) {
                    val += pw[rk[r]] * now[i] % mod;
                    if (val >= mod) val -= mod;
                    nxt.pb(now[i + 1]), res[now[i]] = rk[r];
                } else {
                    val += pw[rk[r]] * now[i + 1] % mod;
                    if (val >= mod) val -= mod;
                    nxt.pb(now[i]), res[now[i + 1]] = rk[r];
                }
                pt++;
            }
            now = nxt;
            r--;
        }
        m1[now[0]][val] = res;
    }
    for (int s = 0; s < 1 << m - 1; ++s) {
        vector <int> res(m << 1, -1);
        int val = 0;
        vector <int> now(m);
        iota(all(now), m);
        int pt = 0, r = k;
        while (now.size() > 1) {
            vector <int> nxt;
            for (int i = 0; i < now.size(); i += 2) {
                if (s >> pt & 1) {
                    val += pw[rk[r]] * now[i] % mod;
                    if (val >= mod) val -= mod;
                    nxt.pb(now[i + 1]), res[now[i]] = rk[r];
                } else {
                    val += pw[rk[r]] * now[i + 1] % mod;
                    if (val >= mod) val -= mod;
                    nxt.pb(now[i]), res[now[i + 1]] = rk[r];
                }
                pt++;
            }
            now = nxt;
            r--;
        }
        int rw = now[0];
        for (int lw = 0; lw < m; ++lw) {
            int tmp = hsh - val;
            if (tmp < 0) tmp += mod;
            tmp -= pw[1] * rw % mod;
            if (tmp < 0) tmp += mod;
            tmp -= pw[2] * lw % mod;
            if (tmp < 0) tmp += mod;
            if (m1[lw].count(tmp)) {
                vector <int> ans = m1[lw][tmp];
                for (int i = 0; i < m; ++i) {
                    res[i] = ans[i];
                }
                for (int i = 0; i < m << 1; ++i) {
                    if (i == lw) cout << 2 << ' ';
                    else if (i == rw) cout << 1 << ' ';
                    else cout << res[i] << ' ';
                }
                cout << endl;
                return 0;
            }
            tmp = hsh - val;
            if (tmp < 0) tmp += mod;
            tmp -= pw[2] * rw % mod;
            if (tmp < 0) tmp += mod;
            tmp -= pw[1] * lw % mod;
            if (tmp < 0) tmp += mod;
            if (m1[lw].count(tmp)) {
                vector <int> ans = m1[lw][tmp];
                for (int i = 0; i < m; ++i) {
                    res[i] = ans[i];
                }
                for (int i = 0; i < m << 1; ++i) {
                    if (i == lw) cout << 1 << ' ';
                    else if (i == rw) cout << 2 << ' ';
                    else cout << res[i] << ' ';
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << "-1\n";
}
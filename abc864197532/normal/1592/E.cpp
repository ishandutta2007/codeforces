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

vector <int> a;
int pre[N][logN];
int ans;

void solve(vector <int> id, int k) {
    if (id.size() <= 1)
        return;
    if (k == -1)
        return;
    vector <int> v[2];
    int bck = 0;
    v[0].pb(0);
    for (int i = 0; i + 1 < id.size(); ++i) {
        if (pre[id[i + 1]][k] - pre[id[i]][k] == id[i + 1] - id[i]) {
            bck += id[i + 1] - id[i];
            v[bck & 1].pb(bck);
        } else {
            if (v[0].size() >= 2) 
                ans = max(ans, v[0].back() - v[0][0]);
            if (v[1].size() >= 2)
                ans = max(ans, v[1].back() - v[1][0]);
            v[0].clear(), v[1].clear(), bck = 0, v[0].pb(0);
        }
    }
    if (v[0].size() >= 2) 
        ans = max(ans, v[0].back() - v[0][0]);
    if (v[1].size() >= 2)
        ans = max(ans, v[1].back() - v[1][0]);
    v[0].clear(), v[1].clear();
    for (int i : id)
        v[a[i] >> k & 1].pb(i);
    solve(v[0], k - 1), solve(v[1], k - 1);
}

int main () {
    owo;
    int n;
    cin >> n;
    a.resize(n + 1);
    for (int i = 0, x; i < n; ++i) {
        cin >> x, a[i + 1] = a[i] ^ x;
        for (int j = 0; j < logN; ++j)
            pre[i + 1][j] = pre[i][j] + (x >> j & 1);
    }
    vector <int> now(n + 1);
    iota(all(now), 0);
    solve(now, 19);
    cout << ans << endl;
}
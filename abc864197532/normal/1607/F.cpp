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
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 4e6 + 1, logN = 18, K = 1 << 9, G = 3;

int nxt[N], dep[N], vis[N], ed, n, m;

void dfs(int v) {
    if (v == n * m)
        return;
    int u = nxt[v];
    if (!vis[u]) {
        vis[u] = vis[v] + 1;
        dfs(u);
        dep[v] = dep[u] + (ed == -1);
        if (v == ed) {
            ed = -1;
        }
    } else if (vis[u] == -1) {
        dep[v] = dep[u] + 1;
    } else {
        dep[v] = vis[v] - vis[u] + 1;
        ed = u;
    }
    vis[v] = -1;
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            for (int j = 0; j < m; ++j) {
                int ni = i, nj = j;
                if (s[j] == 'L')
                    nj--;
                if (s[j] == 'R')
                    nj++;
                if (s[j] == 'U')
                    ni--;
                if (s[j] == 'D')
                    ni++;
                if (0 <= ni && ni < n && 0 <= nj && nj < m) {
                    nxt[i * m + j] = ni * m + nj;
                } else {
                    nxt[i * m + j] = n * m;
                }
                dep[i * m + j] = vis[i * m + j] = 0;
            }
        }
        dep[n * m] = 0;
        vis[n * m] = -1;
        for (int i = 0; i < n * m; ++i) if (!vis[i]) {
            vis[i] = 1;
            ed = -1;
            dfs(i);
        }
        int p = max_element(dep, dep + n * m) - dep;
        cout << p / m + 1 << ' ' << p % m + 1 << ' ' << dep[p] << endl;
    }
}
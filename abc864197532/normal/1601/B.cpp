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
const int mod = 998244353, N = 1000001, logN = 19, K = 1 << 9;

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> a(n), b(n), to(n + 1);
    for (int i = n - 1; ~i; --i) {
        cin >> a[i];
    }
    for (int i = n - 1; ~i; --i) {
        cin >> b[i];
        to[i] = i - b[i];
    }
    to[n] = n;
    set <int> alive;
    vector <int> dis(n + 1, -1);
    vector <pii> par(n + 1);
    queue <int> q;
    q.push(0), dis[0] = 0;
    for (int i = 1; i <= n; ++i)
        alive.insert(i);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        vector <int> move;
        for (auto it = alive.lower_bound(v); it != alive.end() && *it <= v + a[v]; ++it) {
            move.pb(*it);
        }
        for (int i : move) {
            alive.erase(i);
            if (dis[to[i]] != -1)
                continue;
            dis[to[i]] = dis[v] + 1;
            par[to[i]] = mp(i, v);
            q.push(to[i]);
        }
    }
    cout << dis[n] << endl;
    if (dis[n] == -1)
        return 0;
    int v = n;
    vector <int> ans;
    while (v) {
        ans.pb(n - par[v].X);
        v = par[v].Y;
    }
    reverse(all(ans));
    printv(all(ans));

}
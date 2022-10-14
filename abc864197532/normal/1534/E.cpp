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
const int mod = 1e9 + 7, N = 2001, logN = 20, K = 350;

int ask(vector <int> a) {
    cout << "? ";
    for (int i : a) cout << i << ' ';
    cout << endl;
    int x;
    cin >> x;
    return x;
}

int main () {
    owo;
    int n, k;
    cin >> n >> k;
    if (n == k) {
        vector <int> a;
        for (int i = 1; i <= n; ++i) a.pb(i);
        int x = ask(a);
        cout << "! " << x << endl;
        return 0;
    }
    vector <int> dis(n + 1, -1), from(n + 1, -1);
    queue <int> q;
    q.push(k);
    dis[k] = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i = min(k, v); i >= 0; --i) {
            int now = v + k - i - i;
            if (0 <= now && now <= n && v + k - i <= n && dis[now] == -1) {
                dis[now] = dis[v] + 1;
                from[now] = v;
                q.push(now);
            }
        }
    }
    if (dis[n] == -1) {
        cout << -1 << endl;
        return 0;
    }
    vector <int> res;
    int now = n;
    do {
        res.pb(now);
        now = from[now];
    } while (now != k);
    reverse(all(res));
    vector <int> in(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (i <= k) in[i] = true;
    }
    vector <int> a;
    for (int i = 1; i <= k; ++i) a.pb(i);
    int xorr = ask(a);
    now = k;
    for (int i = 0; i < res.size(); ++i) {
        int del = (now + k - res[i]) / 2, oth = k - del;
        vector <int> cur;
        for (int i = 1; i <= n; ++i) {
            if (in[i] && del) cur.pb(i), del--, in[i] = false;
            else if (!in[i] && oth) cur.pb(i), oth--, in[i] = true;
        }
        xorr ^= ask(cur);
        now = res[i];
    }
    cout << "! " << xorr << endl;
}
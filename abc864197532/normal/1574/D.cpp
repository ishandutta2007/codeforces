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
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1000001, logN = 20, K = 48763, KK = 331983854;

vector <vector <int>> a;

struct state {
    vector <int> cur;
    int val;
    bool operator < (const state &o) const {
        return val < o.val;
    }
};

int main () {
    owo;
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0, sz; i < n; ++i) {
        cin >> sz;
        a[i].resize(sz);
        for (int &j : a[i])
            cin >> j;
    }
    set <vector <int>> ban;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        vector <int> in(n);
        for (int i = 0; i < n; ++i)
            cin >> in[i], --in[i];
        ban.insert(in);
    }
    priority_queue <state> pq;
    set <vector <int>> vis;
    state A;
    A.val = 0;
    A.cur.resize(n);
    for (int i = 0; i < n; ++i)
        A.cur[i] = a[i].size() - 1, A.val += a[i].back();
    pq.push(A);
    vis.insert(A.cur);
    while (!pq.empty()) {
        state A = pq.top(); pq.pop();
        if (!ban.count(A.cur)) {
            for (int i = 0; i < n; ++i)
                cout << A.cur[i] + 1 << ' ';
            cout << endl;
            return 0;
        }
        for (int i = 0; i < n; ++i) if (A.cur[i]) {
            A.val -= a[i][A.cur[i]];
            A.cur[i]--;
            A.val += a[i][A.cur[i]];
            if (!vis.count(A.cur))
                pq.push(A), vis.insert(A.cur);
            A.val -= a[i][A.cur[i]];
            A.cur[i]++;
            A.val += a[i][A.cur[i]];
        }
    }
}
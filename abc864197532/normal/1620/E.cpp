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
    if (a.empty())
        return o << "{}";
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
const int mod = 1e9 + 7, N = 500005, logN = 17, K = 350;

int dsu[N << 1];

int Find(int x) {
    if (dsu[x] == x)
        return x;
    return dsu[x] = Find(dsu[x]);
}

int main () {
    owo;
    int q;
    cin >> q;
    iota(dsu, dsu + N * 2, 0);
    int pos = N;
    vector <int> cur(N);
    vector <int> r(N << 1);
    iota(all(cur), 0);
    iota(all(r), 0);
    vector <int> idx;
    while (q--) {
        int t, x, y;
        cin >> t >> x;
        if (t == 1) {
            idx.pb(pos);
            dsu[pos++] = cur[x];
        } else {
            cin >> y;
            if (x == y)
                continue;
            dsu[Find(cur[x])] = Find(cur[y]);
            r[pos] = x;
            cur[x] = pos++;
        }
    }
    for (int i : idx) {
        cout << r[Find(i)] << ' ';
    }
    cout << endl;
}
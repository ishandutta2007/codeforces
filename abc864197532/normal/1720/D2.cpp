#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 333333, M = N * 40;

void upd(int &i, int j) {
    i = max(i, j);
}

struct Trie {
    int ch[M][2], v[M][2][2], sz;
    void reset() {
        for (int i = 0; i < sz; ++i) {
            for (int ii : {0, 1})
                ch[i][ii] = 0;
            for (int ii : {0, 1}) for (int jj : {0, 1})
                v[i][ii][jj] = 0;
        }
        sz = 1;
    }
    void insert(int x, int pos, int val) {
        int now = 0, t = x ^ pos;
        for (int i = 29; ~i; --i) {
            if (!ch[now][t >> i & 1]) {
                ch[now][t >> i & 1] = sz++;
            }
            now = ch[now][t >> i & 1];
            upd(v[now][x >> i & 1][pos >> i & 1], val);
        }
    }
    int query(int x, int pos) {
        int ans = 0, now = 0, t = x ^ pos;
        for (int i = 29; ~i; --i) {
            if (ch[now][~t >> i & 1]) {
                int l = pos >> i & 1, r = x >> i & 1;
                for (int ii : {0, 1}) for (int jj : {0, 1}) {
                    if ((l ^ ii) < (r ^ jj))
                        ans = max(ans, v[ch[now][~t >> i & 1]][ii][jj]);
                }
            }
            if (!ch[now][t >> i & 1])
                break;
            now = ch[now][t >> i & 1];
        }
        return ans;
    }
} tr;

void solve() {
    int n;
    cin >> n;
    vector <int> dp(n, 0);
    tr.reset();
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        dp[i] = tr.query(x, i) + 1;
        tr.insert(x, i, dp[i]);
    }
    cout << *max_element(all(dp)) << '\n';
}

int main () {
    owo;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
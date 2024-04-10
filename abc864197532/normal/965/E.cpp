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
#define owo
#else
#define test(args...)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 100001, logN = 20, K = 111;

priority_queue <int> pq[N];

struct trie {
    vv <int> ch;
    vector <bool> cnt;
    trie() {expend();}
    void expend() {
        ch.pb(vector <int>(26, 0));
        cnt.pb(false);
    }
    int getnxt(int u, int c) {
        if (ch[u][c]) return ch[u][c];
        expend();
        return ch[u][c] = ch.size() - 1;
    }
    void insert(string s) {
        int now = 0;
        for (char c : s) {
            now = getnxt(now, c - 'a');
        }
        cnt[now] = true;
    }
    void dfs(int v, int d = 0) {
        for (int i = 0; i < 26; ++i) if (ch[v][i]) {
            int u = ch[v][i];
            dfs(u, d + 1);
            while (!pq[u].empty()) pq[v].push(pq[u].top()), pq[u].pop();
        }
        if (v && !cnt[v]) pq[v].pop(); // can replace
        pq[v].push(d);
    }
} T;

int main () {
    owo;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        T.insert(s);
    }
    T.dfs(0);
    int ans = 0;
    while (!pq[0].empty()) {
        test(pq[0].top());
        ans += pq[0].top(),  pq[0].pop();
    }
    cout << ans << endl;
}
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
const int mod = 998244353, N = 4000, logN = 20, K = 111, C = 7;

struct Dsu {
    int dsu[N], size[N], n, cc;
    Dsu (int _n) : n(_n), cc(_n) {
        for (int i = 0; i < n; ++i) {
            dsu[i] = i;
            size[i] = 1;
        }
    }
    int Find(int v) {
        if (dsu[v] == v) return v;
        return dsu[v] = Find(dsu[v]);
    }
    bool Union(int v, int u) {
        int x = Find(v), y = Find(u);
        if (x == y) return false;
        if (size[x] > size[y]) swap(x, y);
        dsu[x] = y;
        size[y] += size[x];
        size[x] = 0;
        cc--;
        return true;
    }
    bool same(int u, int v) {
        return Find(u) == Find(v);
    }
};

int main () {
    owo;
    string s;
    cin >> s;
    reverse(all(s));
    int n = s.length();
    if (s[0] == '1')
        return cout << 0 << endl, 0;
    s[0] = '0';
    int ans = 0;
    for (int len = 1; len < n; ++len) {
        Dsu dsu(n * 4);
        for (int i = 0; i < len; ++i) {
            dsu.Union(i, len - i - 1);
            dsu.Union(i + n * 2, len - i - 1 + n * 2);
        }
        for (int i = 0; i < n; ++i) {
            dsu.Union(i + n, n - i - 1 + n);
            dsu.Union(i + n * 3, n - i - 1 + n * 3);   
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                dsu.Union(i, i + n * 3);
                dsu.Union(i + n, i + n * 2);
            }
            if (s[i] == '0') {
                dsu.Union(i, i + n);
                dsu.Union(i + n * 2, i + n * 3);
            }
        }
        vector <bool> choose(n * 4, false);
        int add = 1;
        for (int i = 0; i < n * 2; ++i) {
            if (dsu.same(i, i + n * 2)) {
                add = 0;
            }
        }
        for (int i = len; i < n; ++i) {
            // must 0
            choose[dsu.Find(i)] = true;
        }
        for (int i = 0; i < len; ++i) {
            if (choose[dsu.Find(i)] && choose[dsu.Find(i + n * 2)])
                add = 0;
            if (choose[dsu.Find(i)] || choose[dsu.Find(i + n * 2)])
                continue;
            add = add * 2 % mod;
            choose[dsu.Find(i)] = true;
        }
        for (int i = n; i < n * 2; ++i) {
            if (choose[dsu.Find(i)] && choose[dsu.Find(i + n * 2)])
                add = 0;
            if (choose[dsu.Find(i)] || choose[dsu.Find(i + n * 2)])
                continue;
            add = add * 2 % mod;
            choose[dsu.Find(i)] = true;
        }
        ans += add;
        if (ans >= mod)
            ans -= mod;
    }
    cout << ans << endl;
}
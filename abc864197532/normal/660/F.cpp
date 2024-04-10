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
const int mod = 998244353, N = 2000001, logN = 18, G = 3;

struct line {
    long long m, k;
    line (long long _m, long long _k) : m(_m), k(_k) {}
    long long f(long long x) {return m * x + k;}
};

struct Seg {
    // query max
    // 0-indexed, [l, r)
    int l, r, m;
    line best;
    Seg* ch[2];
    Seg () = default;
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), best(line(0, -1ll << 60)) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void add(line cur) {
        if (r - l == 1) {
            if (cur.f(l) > best.f(l)) {
                best = cur;
            }
        } else {
            if (cur.m < best.m)
                swap(cur, best);
            if (cur.f(m) > best.f(m)) {
                swap(cur, best);
                ch[0]->add(cur);
            } else {
                ch[1]->add(cur);
            }
        }
    }
    long long query(int x) {
        if (r - l == 1)
            return best.f(x);
        return max(best.f(x), ch[x >= m]->query(x));
    }
};

int main () {
    owo;
    // reverse
    // sum_i = pre_0 + ... + pre_i
    // sum_j - sum_i - (j - i) * pre_i
    // sum_j - j * pre_i - sum_i + i * pre_i
    // line = -pre_i * x + (i * pre_i - sum_i)
    // x = j, +sum_j
    int n;
    cin >> n;
    vector <lli> a(n), pre(n + 1), sum(n + 1);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    reverse(all(a));
    for (int i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + a[i - 1];
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + pre[i];
    lli ans = 0;
    Seg root(0, n + 5);
    for (int i = 0; i <= n; ++i) {
        // query
        if (i)
            ans = max(ans, root.query(i) + sum[i]);
        // add
        root.add({-pre[i], i * pre[i] - sum[i]});
    }
    cout << ans << '\n';
}
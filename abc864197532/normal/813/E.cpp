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
const int mod = 1e9 + 7, N = 100005, logN = 17, K = 350, M = N * 40;

struct Seg {
    static Seg mem[M], *pt;
    int l, r, m, sum;
    Seg* ch[2];
    Seg () = default;
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), sum(0) {
        if (r - l > 1) {
            ch[0] = new (pt++) Seg(l, m);
            ch[1] = new (pt++) Seg(m, r);
        }
    }
    void pull() {sum = ch[0]->sum + ch[1]->sum;}
    Seg* modify(int p, int v) {
        Seg* res = new (pt++) Seg(*this);
        if (r - l == 1) {
            res->sum += v;
            return res;
        } else {
            res->ch[p >= m] = ch[p >= m]->modify(p, v);
            res->pull();
            return res;
        }
    }
    int query(int a, int b) {
        if (a <= l && r <= b)
            return sum;
        int ans = 0;
        if (a < m)
            ans += ch[0]->query(a, b);
        if (m < b)
            ans += ch[1]->query(a, b);
        return ans;
    }
} Seg::mem[M], *Seg::pt = mem;

int main () {
    owo;
    int n, k, q;
    cin >> n >> k;
    vector <Seg*> roots;
    roots.pb(new (Seg::pt++) Seg(0, n));
    deque <int> dq[N];
    for (int i = 0, x; i < n; ++i) {
        cin >> x, --x;
        roots.pb(roots.back());
        if (dq[x].size() == k) {
            roots.back() = roots.back()->modify(dq[x].front(), -1);
            dq[x].pop_front();
        }
        roots.back() = roots.back()->modify(i, 1);
        dq[x].pb(i);
    }
    cin >> q;
    int lst = 0, l, r;
    while (q--) {
        cin >> l >> r;
        l = (l + lst) % n, r = (r + lst) % n;
        if (l > r)
            swap(l, r);
        r++;
        lst = roots[r]->query(l, r);
        cout << lst << '\n';
    }
}
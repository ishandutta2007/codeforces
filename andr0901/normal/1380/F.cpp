#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

const int MOD = 998244353;

int add(int x, int y) {
    x += y;
    if (x >= MOD)
        return x - MOD;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0)
        return x + MOD;
    return x;
}

int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}

int mul(int x, int y, int z) {
    return mul(x, mul(y, z));
}

int bin_pow(int a, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return (1LL * bin_pow(a, p - 1) * a) % MOD;
    int t = bin_pow(a, p / 2);
    return (1LL * t * t) % MOD;
}

int inv(int x) {
    return bin_pow(x, MOD - 2);
}

int pairs[10][10];

struct Node {
    int l, r;
    int d[2][2];
};

vector <int> numbers;

Node merge_tr(Node a, Node b) {
    if (a.l == -1)
        return b;
    if (b.l == -1)
        return a;
    Node c;
    c.l = a.l, c.r = b.r;
    c.d[0][0] = mul(a.d[0][0], b.d[0][0]);
    c.d[0][1] = mul(a.d[0][0], b.d[0][1]);
    c.d[1][0] = mul(a.d[1][0], b.d[0][0]);
    c.d[1][1] = mul(a.d[1][0], b.d[0][1]);
    if (numbers[a.r]) {
        c.d[0][0] = add(c.d[0][0], mul(a.d[0][1], pairs[numbers[a.r]][numbers[b.l]], b.d[1][0]));
        c.d[0][1] = add(c.d[0][1], mul(a.d[0][1], pairs[numbers[a.r]][numbers[b.l]], b.d[1][1]));
        c.d[1][0] = add(c.d[1][0], mul(a.d[1][1], pairs[numbers[a.r]][numbers[b.l]], b.d[1][0]));
        c.d[1][1] = add(c.d[1][1], mul(a.d[1][1], pairs[numbers[a.r]][numbers[b.l]], b.d[1][1]));
    }
    return c;
}


template <typename T>
class SegTree{
private: 
    int n;
    vector <T> tr;
    T neutral_tr = {-1, -1, {{0, 0}, {0, 0}}};

    template <typename U>
    void build(int v, int vl, int vr, const vector <U>& a) {
        if (vr - vl < 1)
            return;
        if (vr - vl == 1) {
            tr[v] = {vl, vr - 1, {{pairs[0][a[vl]], 1}, {1, 0}}};
            return;
        }
        int vm = vl + vr >> 1;
        build(2 * v, vl, vm, a), build(2 * v + 1, vm, vr, a);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }

    void upd(int v, int vl, int vr, int i, int x) {
        if (vr - vl == 1) {
            tr[v] = {vl, vr - 1, {{pairs[0][x], 1}, {1, 0}}};
            return;
        }
        int vm = vl + vr >> 1;
        if (i < vm)
            upd(2 * v, vl, vm, i, x);
        else
            upd(2 * v + 1, vm, vr, i, x);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }

    T get(int v, int vl, int vr, int l, int r) {
        if (vr <= l || r <= vl)
            return neutral_tr;
        if (l <= vl && vr <= r)
            return tr[v];
        int vm = vl + vr >> 1;
        return merge_tr(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
    }
public:
    template <typename U>
    SegTree(const vector <U>& a) : n(sz(a)) {
        tr.resize(4 * n, neutral_tr);
        build(1, 0, n, a);
    }


    void upd(int i, int x) {
        upd(1, 0, n, i, x);
    }

    T get(int l, int r) {
        return get(1, 0, n, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    forn (i, 0, 10)
        forn (j, 0, 10)
            pairs[i][j] = 0;
    forn (i, 0, 10)
        forn (j, 0, 10) {
            int s = i + j;
            pairs[s / 10][s % 10]++;
        }
    int n, m;
    cin >> n >> m;
    numbers.resize(n);
    forn (i, 0, n) {
        char c;
        cin >> c;
        numbers[i] = c - '0';
    }
    SegTree <Node> tr(numbers);
    cerr << tr.get(0, n).d[0][0] << " " << tr.get(0, n).d[1][0] << " " << tr.get(0, n).d[0][1] << " " << tr.get(0, n).d[1][1] << "\n";
    while (m --> 0) {
        int i, d;
        cin >> i >> d, --i;
        numbers[i] = d;
        tr.upd(i, d);
        cout << tr.get(0, n).d[0][0] << "\n";
        cerr << tr.get(0, n).d[0][0] << " " << tr.get(0, n).d[1][0] << " " << tr.get(0, n).d[0][1] << " " << tr.get(0, n).d[1][1] << "\n";
    }
    return 0;
}
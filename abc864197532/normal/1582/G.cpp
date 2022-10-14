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
const int mod = 998244353, N = 1 << 20, logN = 19, K = 1 << 9;

int lp[N], id[N];

void build() {
    vector <int> p;
    for (int i = 2; i < N; ++i) {
        if (!lp[i]) {
            id[i] = p.size();
            p.push_back(i);
            lp[i] = i;
        }
        for (int j = 0; 1ll * p[j] * i < N; ++j) {
            lp[p[j] * i] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

vector <int> pos[N], val[N];
int stk[N], sz, a[N], n;
lli ans = 0;

struct Seg {
    int l, r, m, lz;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), lz(1 << 30) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void add(int a, int b, int v) {
        if (a >= b)
            return;
        if (a <= l && r <= b)
            lz = min(lz, v);
        else {
            if (a < m)
                ch[0]->add(a, b, v);
            if (m < b)
                ch[1]->add(a, b, v);
        }
    }
    void travelsal(int cur) {
        cur = min(cur, lz);
        if (r - l == 1)
            ans += min(n, cur) - l;
        else {
            ch[0]->travelsal(cur);
            ch[1]->travelsal(cur);
        }
    }
};

int main () {
    owo;
    build();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        int c = s[i] == '*' ? 1 : -1;
        while (a[i] > 1) {
            int x = lp[a[i]];
            pos[x].pb(i), val[x].pb(0);
            while (a[i] % x == 0)
                a[i] /= x, val[x].back() += c;
        }
    }
    Seg root(0, n);
    for (int j = 0; j < N; ++j) if (!pos[j].empty()) {
        sz = 0;
        pos[j].pb(n), val[j].pb(0);
        for (int i = pos[j].size() - 1; ~i; --i) {
            if (i + 1 < pos[j].size())
                val[j][i] += val[j][i + 1];
            while (sz && val[j][i] >= val[j][stk[sz - 1]]) {
                sz--;
            }
            if (sz) {
                root.add(i ? pos[j][i - 1] + 1 : 0, pos[j][i] + 1, pos[j][stk[sz - 1] - 1]);
            }
            stk[sz++] = i;
        }
    }
    root.travelsal(1 << 30);
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define lli int_fast64_t
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
const int mod = 998244353, N = 200005, logN = 18, M = 2e6;

int R[N], C[N];

struct Seg {
    static Seg mem[M], *pt;
    int l, r, m;
    lli vala, valb; // cost = at + b
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), vala(0), valb(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
            pull();
        } else {
            vala = R[l];
        }
    }
    Seg () = default;
    lli get(int t) {return vala * t + valb;}
    void pull() {vala = ch[0]->vala + ch[1]->vala, valb = ch[0]->valb + ch[1]->valb;}
    Seg* modify(int p, lli va, lli vb) {
        Seg *res = new Seg(*this);
        if (r - l == 1) {
            res->vala += va, res->valb += vb;
        } else {
            res->ch[p >= m] = ch[p >= m]->modify(p, va, vb);
            res->pull();
        }
        return res;
    }
    int query(int a, int b, int t, lli h, lli &used) {
        if (r - l == 1) {
            if (h >= used + get(t)) {
                used += get(t);
                return -1;
            }
            return l;
        }
        if (a <= l && r <= b) {
            if (h >= used + get(t)) {
                used += get(t);
                return -1;
            } else {
                if (h >= used + ch[0]->get(t)) {
                    used += ch[0]->get(t);
                    return ch[1]->query(a, b, t, h, used);
                }
                return ch[0]->query(a, b, t, h, used);
            }
        } else {
            if (a < m) {
                int tmp = ch[0]->query(a, b, t, h, used);
                if (tmp != -1)
                    return tmp;
            }
            if (m < b) {
                int tmp = ch[1]->query(a, b, t, h, used);
                if (tmp != -1)
                    return tmp;
            }
            return -1;
        }
    }
} Seg::mem[M], *Seg::pt = mem;

struct segment {
    int l, r; // tower segment
    lli h; // last tower current health
    int t; // current state time
};

lli get(int id, lli h, int t) {
    return min(h + 1ll * R[id] * t, 1ll * C[id]);
}

vector <segment> stk;
vector <Seg*> roots;
int n;

lli query(int t, lli h) {
    while (!stk.empty()) {
        segment i = stk.back(); stk.pop_back();
        if (i.r - i.l > 1) {
            lli used = 0;
            int p = roots[t - i.t]->query(i.l, i.r - 1, t - i.t, h, used);
            if (p == -1) {
                h -= used;
            } else {
                stk.pb({p + 1, i.r, i.h, i.t});
                stk.pb({0, p + 1, get(p, 0, t - i.t) - h + used, t});
                return 0;
            }
        }
        if (h >= get(i.r - 1, i.h, t - i.t))
            h -= get(i.r - 1, i.h, t - i.t);
        else {
            stk.pb({0, i.r, get(i.r - 1, i.h, t - i.t) - h, t});
            return 0;
        }
    }
    stk.pb({0, n, 0, t});
    return h;
}

int main () {
    owo;
    int q;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> C[i] >> R[i];
    for (int i = n - 1; ~i; --i)
        stk.pb({i, i + 1, C[i], 0});
    vector <vector <int>> chg_time(N);
    for (int i = 0; i < n; ++i) {
        int now = C[i] / R[i] + 1;
        if (now < N)
            chg_time[now].pb(i);
    }
    roots.pb(new Seg(0, n));
    for (int t = 1; t < N; ++t) {
        Seg *res = new Seg(*roots.back());
        for (int id : chg_time[t]) {
            res = res->modify(id, -R[id], C[id]);
        }
        roots.pb(res);
    }
    cin >> q;
    lli ans = 0;
    while (q--) {
        int t; lli h;
        cin >> t >> h;
        lli res = query(t, h);
        ans += res;
    }
    cout << ans << '\n';
}
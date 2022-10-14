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
const int mod = 1e9 + 7, N = 100001, logC = 30, K = 450;

int a[N], p[K], m, lst[N << 1], cnt[N];

struct Seg1 {
    int mx[N << 1];
    void build() {
        for (int i = 0; i < N; ++i)
            mx[i + N] = cnt[i];
        for (int i = N - 1; ~i; --i) {
            mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
        }
    }
    int query(int l, int r) {
        int ans = 0;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                ans = max(ans, mx[l++]);
            if (r & 1)
                ans = max(ans, mx[--r]);
        }
        return ans;
    }
};

struct Seg2 {
    static Seg2 mem[N * 40], *pt;
    int l, r, res;
    Seg2* ch[2];
    Seg2 () = default;
    Seg2 (int _l, int _r) : l(_l), r(_r), res(1) {
        if (r - l > 1) {
            ch[0] = new (pt++) Seg2(l, l + r >> 1);
            ch[1] = new (pt++) Seg2(l + r >> 1, r);
        }
    }
    void pull() {res = 1ll * ch[0]->res * ch[1]->res % mod;}
    Seg2* modify(int p, int val) {
        Seg2* ans = new (pt++) Seg2(*this);
        if (r - l == 1) {
            ans->res = 1ll * ans->res * val % mod;
        } else {
            ans->ch[p >= (l + r >> 1)] = ans->ch[p >= (l + r >> 1)]->modify(p, val);
            ans->pull();
        }
        return ans;
    }
    int query(int a, int b) {
        if (a <= l && r <= b)
            return res;
        int ans = 1;
        if (a < (l + r >> 1))
            ans = 1ll * ans * ch[0]->query(a, b) % mod;
        if ((l + r >> 1) < b)
            ans = 1ll * ans * ch[1]->query(a, b) % mod;
        return ans;
    }
} Seg2::mem[N * 40], *Seg2::pt = mem;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1)
            ans = ans * a % mod;
    }
    return ans;
}

int main () {
    owo;
    for (int x = 2; x < K; ++x) {
        int tmp = x;
        bool is = true;
        for (int i = 2; i * i <= tmp; ++i) if (tmp % i == 0)
            is = false;
        if (is) {
            p[m++] = x;
        }
    }
    int n, q;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <Seg1*> roots1;
    for (int j = 0; j < m; ++j) {
        fill(cnt, cnt + N, 0);
        for (int i = 0; i < n; ++i) {
            while (a[i] % p[j] == 0)
                a[i] /= p[j], cnt[i]++;
        }
        roots1.pb(new Seg1());
        roots1.back()->build();
    }
    vector <Seg2*> roots2;
    roots2.pb(new (Seg2::pt++) Seg2(0, n));
    fill(lst, lst + (N << 1), -1);
    for (int i = 0; i < n; ++i) {
        Seg2 *cur = roots2.back()->modify(i, a[i]);
        if (lst[a[i]] != -1)
            cur = cur->modify(lst[a[i]], modpow(a[i], mod - 2));
        lst[a[i]] = i;
        roots2.pb(cur);
    }
    cin >> q;
    int lst = 0, l, r;
    while (q--) {
        cin >> l >> r;
        l = (l + lst) % n, r = (r + lst) % n;
        if (l > r)
            swap(l, r);
        r++;
        lst = 1;
        for (int i = 0; i < m; ++i) {
            lst = 1ll * modpow(p[i], roots1[i]->query(l, r)) * lst % mod;
        }
        lst = 1ll * roots2[r]->query(l, r) * lst % mod;
        cout << lst << '\n';
    }
}
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5;

struct fenwick {
    int f[N], n;

    void reset() {
        memset(f, 0, sizeof(f));
    }

    void add(int x, int y) {
        while (x <= n) {
            f[x] += y;
            x += (x & -x);
        }
    }

    int query(int x) {
        int ans = 0;
        while (x) {
            ans += f[x];
            x &= (x - 1);
        }
        return ans;
    }
} tr;

int fir[N], f[N], a[N], bs[N]; ll b[N], s[N], suf[N], pre[N];
int n, len; ll ans = -9e18, sum, m;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

ll calc(ll mid) {
    ll res = 0;
    tr.n = len; tr.reset();
    for (int i = n; i >= 1; i--) {
        // s[?] - s[i - 1] >= mid
        // s[?] >= mid + s[i - 1]
        int pos = lower_bound(b + 1, b + len + 1, mid + s[i - 1]) - b;
        tr.add(bs[i], 1);
        if (pos <= len) res += n - i + 1 - tr.query(pos - 1);
    }
    return res;
}

pair <ll, ll> getval(ll m) {
    ll l = -50000ll * n, r = 50000ll * n, ans = l, cnt = -1;
    // >= ans  >= m 
    while (l <= r) {
        ll mid = (l + r) / 2, res = calc(mid);
        if (res >= m) ans = mid, cnt = res, l = mid + 1;
        else r = mid - 1;
    }
    return make_pair(ans, cnt);
}

struct seg {
    int l, r; ll val;
    seg (int a = 0, int b = 0, ll c = 0) : l(a), r(b), val(c) {}
    bool operator < (const seg A) const { return val > A.val; }
} ss[N];

mt19937 rng(1);

struct fhq_treap {
    int ls[N], rs[N], key[N], siz[N], rub[N]; ll val[N], sum[N];
    int root, top, tot; 

    inline int newNode(ll x) {
        int now;
        if (top) now = rub[top--];
        else now = ++tot;
        siz[now] = 1; val[now] = sum[now] = x; key[now] = rng(); ls[now] = rs[now] = 0;
        return now;
    }

    void update(int u) {
        siz[u] = siz[ls[u]] + siz[rs[u]] + 1;
        sum[u] = sum[ls[u]] + sum[rs[u]] + val[u];
    }

    void split(int u, ll x, int &l, int &r) {
        if (!u) { l = r = 0; return; }
        if (val[u] <= x) {
            r = u; split(ls[u], x, l, ls[r]); update(u);
        } else {
            l = u; split(rs[u], x, rs[l], r); update(u);
        }
    }

    void _split(int u, int x, int &l, int &r) {
        if (!u) { l = r = 0; return; }
        if (siz[ls[u]] >= x) {
            r = u; _split(ls[u], x, l, ls[r]); update(u);
        } else {
            l = u; _split(rs[u], x - siz[ls[u]] - 1, rs[l], r); update(u);
        }
    }

    int merge(int l, int r) {
        if (!l || !r) return l ^ r;
        if (key[l] <= key[r]) {
            rs[l] = merge(rs[l], r); update(l); return l;
        } else {
            ls[r] = merge(l, ls[r]); update(r); return r;
        }
    }

    void insert(ll x) {
        // fprintf(stderr, "insert %lld\n", x);
        int l, r, tmp = newNode(x);
        split(root, x, l, r); root = merge(merge(l, tmp), r);
    }

    void erase(ll x) {
        // fprintf(stderr, "erase %lld\n", x);
        int l, r, tmp;
        split(root, x, l, r); _split(r, 1, tmp, r);
        rub[++top] = tmp;
        root = merge(l, r);
    }

    ll getk(int k) {
        int l, r;
        _split(root, k, l, r);
        ll ans = sum[l];
        root = merge(l, r);
        // fprintf(stderr, "k = %d, sum[l] = %lld, siz[l] = %d\n", k, sum[l], siz[l]);
        return ans;
    }
} tr3;

ll smx[N][20], smn[N][20]; int lg[N];

ll qmx(int l, int r) {
    int k = lg[r - l + 1];
    return max(smx[l][k], smx[r - (1 << k) + 1][k]);
}

ll qmn(int l, int r) {
    int k = lg[r - l + 1];
    return min(smn[l][k], smn[r - (1 << k) + 1][k]);
}

ll getval(int i, int j) {
    // return suf[i + 1] + pre[j - 1] + s[i] - s[j - 1];

    // fprintf(stderr, "i = %d, j = %d, res = %lld\n", i, j, qmx(i, j - 1) - qmn(i, j - 1));
    return qmx(i, j - 1) - qmn(i, j - 1);
}

int sy;
void cover(int l, int r) {
    while (find(l) <= r) {
        --sy;
        int x = find(l), lx = fir[x] - 1, rx = find(x + 1);
        if (lx) tr3.erase(getval(lx, x));
        if (rx != n + 1) tr3.erase(getval(x, rx));
        if (lx && rx != n + 1) tr3.insert(getval(lx, rx));
        f[x] = x + 1; fir[find(x + 1)] = fir[x];
    }
}

vector <int> vec[N];
int seq[N];
int slen, seqlen;

struct seg_t {
    int mx[N << 2], cnt[N << 2]; ll sum[N << 2];

    void reset() {
        memset(mx, 0, sizeof(mx));
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
    }

    void add(int u, int l, int r, int x, int y, ll z) {
        mx[u] = max(mx[u], y); ++cnt[u]; sum[u] += z;
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (mid >= x) add(u << 1, l, mid, x, y, z);
        else add(u << 1 | 1, mid + 1, r, x, y, z);
    }

    int qcnt(int u, int L, int R, int l, int r) {
        if (l <= L && R <= r) return cnt[u];
        int mid = (L + R) >> 1, ans = 0;
        if (mid >= l) ans += qcnt(u << 1, L, mid, l, r);
        if (mid + 1 <= r) ans += qcnt(u << 1 | 1, mid + 1, R, l, r);
        return ans;
    }

    int qmx(int u, int L, int R, int l, int r) {
        if (l <= L && R <= r) return mx[u];
        int mid = (L + R) >> 1, ans = 0;
        if (mid >= l) ans = max(ans, qmx(u << 1, L, mid, l, r));
        if (mid + 1 <= r) ans = max(ans, qmx(u << 1 | 1, mid + 1, R, l, r));
        return ans;
    }

    ll qsum(int u, int L, int R, int l, int r) {
        if (l <= L && R <= r) return sum[u];
        int mid = (L + R) >> 1; ll ans = 0;
        if (mid >= l) ans += qsum(u << 1, L, mid, l, r);
        if (mid + 1 <= r) ans += qsum(u << 1 | 1, mid + 1, R, l, r);
        return ans;
    }

    void findseg(int u, int L, int R, int l, int r) {
        if (!cnt[u]) return;
        if (L == R) {
            for (auto i : vec[L]) seq[++seqlen] = i;
            return;
        }
        int mid = (L + R) >> 1;
        if (mid >= l) findseg(u << 1, L, mid, l, r);
        if (mid + 1 <= r) findseg(u << 1 | 1, mid + 1, R, l, r);
    }
} tr2;

//  [l, r]  lim 
void getseg(ll l, ll r, ll lim, ll lim2) {
    if (l > r) return;
    tr2.reset();
    for (int i = 1; i <= len; i++) vec[i].clear();
    for (int i = n; i >= 1; i--) {
        int posl = lower_bound(b + 1, b + len + 1, l + s[i - 1]) - b;
        int posr = upper_bound(b + 1, b + len + 1, r + s[i - 1]) - b - 1;
        // fprintf(stderr, "l = %lld, r = %lld, posl = %d, posr = %d\n", l, r, posl, posr);
        vec[bs[i]].push_back(i); tr2.add(1, 1, len, bs[i], i, s[i]);
        if (posl <= posr) {
            if (!lim) {
                if (lim2) {
                    int tmp = tr2.qcnt(1, 1, len, posl, posr);
                    sum += l * min(lim2, (ll)tmp);
                    cover(i, tr2.qmx(1, 1, len, posl, posr));
                    lim2 = max(0ll, lim2 - tmp);
                }
                continue;
            }
            seqlen = 0; tr2.findseg(1, 1, len, posl, posr);
            int j;
            for (j = 1; j <= seqlen && lim; j++) {
                // if (i == 54840) fprintf(stderr, "j = %d, sum = %lld, slen = %d\n", j, sum, slen);
                ss[++slen] = seg(i, seq[j], s[seq[j]] - s[i - 1]);
                // fprintf(stderr, "i = %d, seq[j] = %d\n", i, seq[j]);
                --lim;
            }
            for (; j <= seqlen && lim2; j++) {
                cover(i, seq[j]);
                sum += s[seq[j]] - s[i - 1];
                --lim2;
            }
        }
        // if (sum < 10000) fprintf(stderr, "i = %d, sum = %lld\n", i, sum);
    }
}

void getcover(ll mid) {
    tr2.reset();
    for (int i = n; i >= 1; i--) {
        tr2.add(1, 1, len, bs[i], i, s[i]);
        int pos = lower_bound(b + 1, b + len + 1, mid + s[i - 1]) - b;
        sum += tr2.qsum(1, 1, len, pos, len) - 1ll * tr2.qcnt(1, 1, len, pos, len) * s[i - 1];
        cover(i, tr2.qmx(1, 1, len, pos, len));
    }
}

int main() {
    // freopen("road.in", "r", stdin);
    // freopen("road.out", "w", stdout);
    read(n); read(m);
    for (int i = 1; i <= n; i++) read(a[i]), s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) pre[i] = max(0ll, pre[i - 1] + a[i]);
    for (int i = n; i >= 1; i--) suf[i] = max(0ll, suf[i + 1] + a[i]);
    for (int i = 0; i <= n; i++) b[++len] = s[i];
    sort(b + 1, b + len + 1); len = unique(b + 1, b + len + 1) - b - 1;
    for (int i = 0; i <= n; i++) bs[i] = lower_bound(b + 1, b + len + 1, s[i]) - b;
    for (int i = 1; i <= n + 1; i++) f[i] = fir[i] = i;
    ll ml = max(1ll, m - n + 1), mr = m;
    sy = n;
    for (int i = 0; i <= n; i++) smx[i][0] = smn[i][0] = s[i];
    for (int j = 1; j <= 19; j++) {
        for (int i = 0; i <= n - (1 << j) + 1; i++) {
            smx[i][j] = max(smx[i][j - 1], smx[i + (1 << (j - 1))][j - 1]);
            smn[i][j] = min(smn[i][j - 1], smn[i + (1 << (j - 1))][j - 1]);
        }
    }
    lg[0] = -1;
    for (int i = 1; i <= n + 1; i++) lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i < n; i++) tr3.insert(getval(i, i + 1));
    pair <ll, ll> v1 = getval(ml), v2 = getval(mr);
    // fprintf(stderr, "v1.first = %lld, v1.second = %lld, v2.first = %lld, v2.second = %lld\n", v1.first, v1.second, v2.first, v2.second);
    getcover(v1.first + 1); getseg(v1.first, v1.first, min(v1.second, mr) - ml + 1, ml - 1 - calc(v1.first + 1));
    getseg(v2.first + 1, v1.first - 1, 1e9, 0);
    if (v1.first != v2.first) getseg(v2.first, v2.first, mr - calc(v2.first + 1), 0);
    int mlen = mr - ml + 1;
    sort(ss + 1, ss + mlen + 1);
    // fprintf(stderr, "slen = %d\n", slen);
    for (int i = 0; i <= mlen; i++) {
        // fprintf(stderr, "l = %d, r = %d, val = %lld\n", ss[i].l, ss[i].r, ss[i].val);
        if (i != 0) cover(ss[i].l, ss[i].r), sum += ss[i].val;
        if (find(1) == n + 1) {
            if (i == mlen) ans = max(ans, sum);
            continue;
        }
        if (mlen - i != 0 && mlen - i <= sy) {
            ll res = sum;
            int tmp = find(1);
            res += (pre[tmp - 1] - s[tmp - 1]);
            tmp = fir[n + 1] - 1;
            res += (suf[tmp + 1] + s[tmp]);
            // fprintf(stderr, "suf[tmp + 1] = %lld, s[tmp] = %lld, tmp = %d\n", suf[tmp + 1], s[tmp], tmp);
            // fprintf(stderr, ">>>>>>>>>>>> i = %d, res = %lld\n", i, res);
            res += tr3.getk(mlen - i - 1);
            ans = max(ans, res);
        }
        // fprintf(stderr, "i = %d, ans = %lld\n", i, ans);
    }
    print(ans, '\n');
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T, typename Cmp=std::greater<int>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

struct node {
    int sm;
    node* l, *r;
};

using pnode = node*;

node nodes[(int) 5e6];
int ndx = 0;

pnode new_node(int sm = 0, pnode l = 0, pnode r = 0) {
    pnode res = &nodes[ndx++];
    res->sm = sm;
    res->l = l;
    res->r = r;
    if (l) {
        res->sm += l->sm;
    }
    if (r) {
        res->sm += r->sm;
    }
    return res;
}

int get_sum(pnode t, int l, int r, int ql, int qr) {
    if (!t || r <= ql || qr <= l || t->sm == 0) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return t->sm;
    }
    int m = (l + r) >> 1;
    return get_sum(t->l, l, m, ql, qr) + get_sum(t->r, m, r, ql, qr);
}

pnode nnset(pnode t, int l, int r, int qi, int qx) {
    if (l + 1 == r) {
        return new_node(qx);
    }
    int m = (l + r) >> 1;
    if (qi < m) {
        return new_node(0, nnset(t ? t->l : new_node(), l, m, qi, qx), t ? t->r : new_node());
    }
    return new_node(0, t ? t->l : new_node(), nnset(t ? t->r : new_node(), m, r, qi, qx));
}

pnode nset(pnode t, int l, int r, int qi, int qx) {
    if (l + 1 == r) {
        return new_node(qx);
    }
    int m = (l + r) >> 1;
    if (qi < m) {
        return new_node(0, nset(t->l, l, m, qi, qx), t->r);
    }
    return new_node(0, t->l, nset(t->r, m, r, qi, qx));
}

int last[111111];
pnode ps[111111];

int used[111111];
int tmu = 0;
int a[111111];

char buf[(int) 3e7];
int bufp = 0;

void prii(int x) {
    int len = 0;
    while (x) {
        buf[bufp++] = x % 10 + '0';
        x /= 10;
        ++len;
    }
    for (int i = 0; i * 2 < len; i++) {
        swap(buf[bufp - 1 - i], buf[bufp - len + i]);
    }
    buf[bufp++] = ' ';
}

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    scanf("%d", &n);
    memset(last, -1, sizeof(last));

//    for (int i = 0; i < n; i++) {
//        ps[0] = nnset(ps[0], 0, n, i, 0);
//    }

    for (int i = 0; i < n; i++) {
//        scid(x);
        int x;
        scanf("%d", &x);
        --x;
        a[i] = x;
        if (i) {
            ps[i] = ps[i - 1];
        }
        if (last[x] != -1) {
            ps[i] = nnset(ps[i], 0, n, last[x], 0);
        }
        ps[i] = nnset(ps[i], 0, n, i, 1);
        last[x] = i;
    }

    for (int k = 1; k <= n; k++) {
        int fst = 0;
        int ans = 0;
        if (k >= 5000) {
            while (fst < n) {
                int l = min(n - 1, fst + k - 1);
                int r = n;
                while (l + 1 < r) {
                    int m = (l + r) >> 1;
                    int x = get_sum(ps[m], 0, n, fst, m + 1);
                    if (x <= k) {
                        l = m;
                    } else {
                        r = m;
                    }
                }
                fst = l + 1;
                ans++;
            }
        } else {
            int ck = 0;
            tmu++;
            ans = 1;
            while (fst < n) {
                if (used[a[fst]] != tmu) {
                    ck++;
                    used[a[fst]] = tmu;
                }
                if (ck > k) {
                    ans++;
                    ck = 1;
                    tmu++;
                    used[a[fst]] = tmu;
                }
                fst++;
            }
        }
        prii(ans);
    }

    puts(buf);

    return 0;
}
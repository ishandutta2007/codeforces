#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

#define mod 1000000007
#define lSon (node << 1)
#define rSon (lSon | 1)

class Buffer {
    public:
        Buffer(int _dim) {
            dim = _dim;
            data.resize(dim + 11);
            refill();
        }

        Buffer& operator>>(int &dest) {
            while (!is_digit(data[pos]))
                if (++pos == dim)
                    refill();

            dest = 0;
            while (is_digit(data[pos])) {
                dest = dest * 10 + data[pos] - '0';
                if (++pos == dim)
                    refill();
            }

            return *this;
        }


    private:
        int pos, dim;
        vector<char> data;

        bool is_digit(char c) {
            return '0' <= c && c <= '9';
        }

        void refill() {
            memset(&data[0], 0, dim);
            fread(&data[0], 1, dim, stdin);
            pos = 0;
        }
};

struct treap {
    treap *son[2];
    int cnt, val;
    int key;

    treap() {
        son[0] = son[1] = NULL;
        val = 0;
        cnt = 0;
        key = -1;
    }

    treap(int _val, treap* lson, treap* rson) {
        val = _val;
        son[0] = lson;
        son[1] = rson;
        cnt = 1;
        key = rand() % mod;
    }
} *nil;

void recomp(treap* &act) {
    if (act == nil) return;
    act->cnt = act->son[0]->cnt + act->son[1]->cnt + 1;
}

void rotleft(treap* &act) {
    treap *aux = act->son[0];
    act->son[0] = aux->son[1];
    aux->son[1] = act;
    act = aux;

    recomp(act);
    recomp(act->son[1]);
}

void rotright(treap* &act) {
    treap *aux = act->son[1];
    act->son[1] = aux->son[0];
    aux->son[0] = act;
    act = aux;

    recomp(act);
    recomp(act->son[0]);
}

void balance(treap* &act) {
    if (act == nil) return;

    if (act->son[0]->key > act->key)
        rotleft(act);
    else
    if (act->son[1]->key > act->key)
        rotright(act);

    recomp(act);
}

void add(treap* &act, int v) {
    if (act == nil) {
        act = new treap(v, nil, nil);
        return;
    }

    if (v < act->val)
        add(act->son[0], v);
    else
        add(act->son[1], v);

    balance(act);
}

void erase(treap* &act, int v) {
    if (act->son[0] == nil && act->son[1] == nil) {
        act = nil;
        return;
    }

    if (act->val == v) {
        if (act->son[0]->key > act->son[1]->key)
            rotleft(act);
        else
            rotright(act);
    }

    if (v < act->val) erase(act->son[0], v);
    if (v > act->val) erase(act->son[1], v);

    recomp(act);
    //balance(act);
}

int lower(treap* act, int v) {
    if (act == nil) return 0;

    if (v < act->val)
        return lower(act->son[0], v);
    else
        return act->cnt - act->son[1]->cnt + lower(act->son[1], v);
}

treap* get_treap(int l, int r) {
    if (l > r) return nil;

    int mid = (l + r) >> 1;
    treap* act = new treap(mid, nil, nil);
    if (l == r) return act;

    act->son[0] = get_treap(l, mid - 1);
    act->son[1] = get_treap(mid + 1, r);
    recomp(act);

    return act;
}

struct aint {
    int n, i;
    vector<treap*> data;

    void build(int node, int l, int r) {
        data[node] = get_treap(l, r);
        if (l == r) return;

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);
    }

    void init(int _n) {
        n = _n;
        data = vector<treap*>(4 * n + 11, nil);
        build(1, 1, n);
    }

    void upd_add(int node, int l, int r, int pos, int v) {
        add(data[node], v);

        if (l == r)
            return;

        int mid = (l + r) >> 1;
        if (pos <= mid)
            upd_add(lSon, l, mid, pos, v);
        else
            upd_add(rSon, mid + 1, r, pos, v);
    }

    void upd_rm(int node, int l, int r, int pos, int v) {
        erase(data[node], v);

        if (l == r)
            return;

        int mid = (l + r) >> 1;
        if (pos <= mid)
            upd_rm(lSon, l, mid, pos, v);
        else
            upd_rm(rSon, mid + 1, r , pos, v);
    }

    int que(int node, int l, int r, int qL, int qR, int v) {
        if (qL > qR) return 0;
        if (qL <= l && r <= qR)
            return lower(data[node], v);

        int ans = 0;
        int mid = (l + r) >> 1;
        if (qL <= mid)
            ans += que(lSon, l, mid, qL, qR, v);
        if (qR > mid)
            ans += que(rSon, mid + 1, r, qL, qR, v);

        return ans;
    }
};


int n, m, i, x, y, p[maxN];
aint work;
ll ans;

void swap_them(int x, int y) {
    if (x > y) swap(x, y);

    ans -= work.que(1, 1, n, x + 1, y - 1, p[x]);
    ans -= max(0, (y - x - 1) - work.que(1, 1, n, x + 1, y - 1, p[y]));

    work.upd_rm(1, 1, n, x, p[x]);
    work.upd_rm(1, 1, n, y, p[y]);

    if (p[x] > p[y])
        ans--;

    swap(p[x], p[y]);

    if (p[x] > p[y])
        ans++;

    work.upd_add(1, 1, n, x, p[x]);
    work.upd_add(1, 1, n, y, p[y]);

    ans += work.que(1, 1, n, x + 1, y - 1, p[x]);
    ans += max(0, (y - x - 1) - work.que(1, 1, n, x + 1, y - 1, p[y]));
}

int main()
{
    //freopen("test.in","r",stdin);
    Buffer fin(1 << 20);
    srand(time(NULL));
    nil = new treap();

    fin >> n >> m;


    work.init(n);
    for (i = 1; i <= n; i++)
        p[i] = i;

    for (i = 1; i <= m; i++) {
        fin >> x >> y;

        if (x != y)
            swap_them(x, y);

        printf("%lld\n", ans);
    }


    return 0;
}
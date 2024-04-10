#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int inf = 1e9+100;
const int nax = 3e5;

struct node {
    int ap, ri;
    node* l;
    node* r;
};

int tsz;
node t[70 * nax];

node* build(int l, int r) {
    node* nv = &t[tsz++];
    if(l == r) {
        if(l == 0) *nv = {-1, 0, 0, 0};
        else *nv = {-1, -inf, 0, 0};
    } else {
        int m = (l + r) >> 1;
        nv->l = build(l, m);
        nv->r = build(m + 1, r);
        nv->ap = -1;
        nv->ri = max(nv->l->ri, nv->r->ri);
    }
    return nv;
}

void push(node* v, int l, int r) {
    int x = v->ap;
    if(x != -1) {
        v->ap = -1;
        node* a = &t[tsz++];
        *a = *(v->l);
        node* b = &t[tsz++];
        *b = *(v->r);
        v->l = a;
        v->r = b;
        v->l->ap = x;
        v->r->ap = x;
        if(x == 1) {
            v->l->ri = (l + r) / 2;
            v->r->ri = r;
        } else {
            v->l->ri = -inf;
            v->r->ri = -inf;
        }
    }
}

node* upd(node* v, int l, int r, int l1, int r1, int val) {
    if(r < l1 || r1 < l) return v;
    node* nv = &t[tsz++];
    if(l1 <= l && r <= r1) {
        if(val == 1) *nv = {val, r, v->l, v->r};
        else *nv = {val, -inf, v->l, v->r};
        return nv;
    }
    push(v, l, r);
    int m = (l + r) >> 1;
    nv->l = upd(v->l, l, m, l1, r1, val);
    nv->r = upd(v->r, m + 1, r, l1, r1, val);
    nv->ap = -1;
    nv->ri = max(nv->l->ri, nv->r->ri);
    return nv;
}

int get(node* v, int l, int r, int l1, int r1) {
    if(r < l1 || r1 < l) return -inf;
    if(l1 <= l && r <= r1) return v->ri;
    push(v, l, r);
    int m = (l + r) >> 1;
    return max(get(v->l, l, m, l1, r1), get(v->r, m + 1, r, l1, r1));
}

int n;
int tot;
vector<node*> rt;
int dam[nax];
int cnt[nax];
int ans[nax];

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout.precision(8); cout << fixed;
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#ifdef HOME
    freopen("in.txt", "r", stdin);
#endif // HOME
    memset(ans, -1, sizeof(ans));
    node* rt0 = build(0, nax - 1);
    cin >> n;
    for(int sn = 1; sn <= n; sn++) {
        int tp; cin >> tp;
        if(tp == 1) {
            rt.pb(rt0);
            cnt[tot++] = 1;
        } else if(tp == 2) {
            int i; cin >> i; i--;
            if(ans[i] != -1) continue;
            dam[i]++;
        } else if(tp == 3) {
            int i; cin >> i; i--;
            if(ans[i] != -1) continue;
            cnt[i]++;
        } else if(tp == 4) {
            int i; cin >> i; i--;
            rt.pb(rt[i]);
            dam[tot] = dam[i];
            cnt[tot] = cnt[i];
            if(ans[i] != -1) {
                ans[tot] = sn;
            }
            tot++;
        } else if(tp == 5) {
            int i, j; cin >> i >> j; i--; j--;
            if(ans[i] != -1 || ans[j] != -1) continue;
            {
                int pos = cnt[i] - 1 - dam[j];
                int ri;
                if(pos < 0 || (ri = get(rt[i], 0, nax - 1, 0, pos)) == -inf) ans[i] = sn;
                else {
                    if(ri != pos) rt[i] = upd(rt[i], 0, nax - 1, ri + 1, pos, 1);
                    rt[i] = upd(rt[i], 0, nax - 1, ri, ri, 0);
                    if(get(rt[i], 0, nax - 1, 0, nax - 1) == -inf) ans[i] = sn;
                }
            }
            {
                int pos = cnt[j] - 1 - dam[i];
                int ri;
                if(pos < 0 || (ri = get(rt[j], 0, nax - 1, 0, pos)) == -inf) ans[j] = sn;
                else {
                    if(ri != pos) rt[j] = upd(rt[j], 0, nax - 1, ri + 1, pos, 1);
                    rt[j] = upd(rt[j], 0, nax - 1, ri, ri, 0);
                    if(get(rt[j], 0, nax - 1, 0, nax - 1) == -inf) ans[j] = sn;
                }
            }
        }
    }
    cout << tot << '\n';
    for(int i = 0; i < tot; i++) cout << ans[i] << ' ';
}
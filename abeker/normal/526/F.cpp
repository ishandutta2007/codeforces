#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 300005;
const int offset = 1 << 19;
const int INF = 0x3f3f3f3f;

struct node {
    int mini, occ, lazy;
    node(int mini, int occ, int lazy) : mini(mini), occ(occ), lazy(lazy) {}
    node() : mini(INF), occ(0), lazy(0) {} 
};

int N;
int a[MAXN];
node t[2 * offset];
stack <pii> inc, dec;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int row, col;
        scanf("%d%d", &row, &col);
        a[row] = col;
    }
}

node merge(node L, node R) {
    node res;
    res.mini = min(L.mini, R.mini);
    if (L.mini == res.mini) res.occ += L.occ;
    if (R.mini == res.mini) res.occ += R.occ;
    res.lazy = L.lazy + R.lazy;
    return res;
}

void init() {
    for (int i = 1; i <= N; i++)
        t[i + offset] = node(0, 1, 0);
    for (int i = offset - 1; i >= 0; i--)
        t[i] = merge(t[2 * i], t[2 * i + 1]);    
}

void prop(int x) {
    t[x].mini += t[x].lazy;
    if (x < offset) {
        t[2 * x].lazy += t[x].lazy;
        t[2 * x + 1].lazy += t[x].lazy;
    }
    t[x].lazy = 0;
}

void update(int x, int lo, int hi, int from, int to, int val) {
    prop(x);
    if (lo >= to || hi <= from) return;
    if (lo >= from && hi <= to) {
        t[x].mini += val;
        if (x < offset) {
            t[2 * x].lazy += val;
            t[2 * x + 1].lazy += val;
        }
        return;
    }
    int mid = (lo + hi) / 2;
    update(2 * x, lo, mid, from, to, val);
    update(2 * x + 1, mid, hi, from, to, val);
    t[x] = merge(t[2 * x], t[2 * x + 1]);
}

void update(int from, int to, int val) {
    update(1, 0, offset, from, to, val);
}

node query(int x, int lo, int hi, int from, int to) {
    prop(x);
    if (lo >= to || hi <= from) return node();
    if (lo >= from && hi <= to) return t[x];
    int mid = (lo + hi) / 2;
    return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

void update_inc(int x) {
    int pos = x;
    for (; !inc.empty() && inc.top().first > a[x]; inc.pop()) {
        update(inc.top().second, pos, inc.top().first - a[x]);
        pos = inc.top().second;
    }
    inc.push(pii(a[x], pos));
}

void update_dec(int x) {
    int pos = x;
    for (; !dec.empty() && dec.top().first < a[x]; dec.pop()) {
        update(dec.top().second, pos, a[x] - dec.top().first);
        pos = dec.top().second;
    }
    dec.push(pii(a[x], pos));
}

ll solve() {
    init();
    ll sol = 0;
    for (int i = 1; i <= N; i++) {
        update(1, i, -1);
        update_inc(i);
        update_dec(i);
        node tmp = query(1, 0, offset, 1, i + 1);
        if (!tmp.mini) sol += tmp.occ;
    }   
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}
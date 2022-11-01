#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const ll INF = 1e18;
#define X first
#define Y second
const int maxn = 3e5;

struct node {
    int ad;
    pair<int, int> o;
} t[4 * maxn];

void build(int v, int l, int r) {
    if(l == r) {
        t[v].o = {0, l};
    } else {
        int m = (l + r) >> 1;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m + 1, r);
        t[v].o = max(t[v * 2 + 1].o, t[v * 2 + 2].o);
    }
}

void push(int v) {
    int x = t[v].ad;
    if(!x) return;
    t[v].ad = 0;
    t[v * 2 + 1].o.X += x;
    t[v * 2 + 1].ad += x;
    t[v * 2 + 2].o.X += x;
    t[v * 2 + 2].ad += x;
}

void upd(int v, int l, int r, int l1, int r1, int x) {
    if(r < l1 || r1 < l) return;
    if(l1 <= l && r <= r1) {
        t[v].ad += x;
        t[v].o.X += x;
        return;
    }
    push(v);
    int m = (l + r) >> 1;
    upd(v * 2 + 1, l, m, l1, r1, x);
    upd(v * 2 + 2, m + 1, r, l1, r1, x);
    t[v].o = max(t[v * 2 + 1].o, t[v * 2 + 2].o);
}

pair<int, int> get(int v, int l, int r, int l1, int r1) {
    if(r < l1 || r1 < l) return make_pair(0, 0);
    if(l1 <= l && r <= r1) return t[v].o;
    push(v);
    int m = (l + r) >> 1;
    return max(get(v * 2 + 1, l, m, l1, r1), get(v * 2 + 2, m + 1, r, l1, r1));
}

struct man {
    int l, v, r;
    bool operator < (const man &he) const {
        return l < he.l;
    }
} a[maxn];

int n, L, R, opt;
vector<man> in[maxn], out[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].v >> a[i].r;
        a[i].l--; a[i].v--; a[i].r--;
        in[a[i].l].push_back(a[i]);
        out[a[i].v].push_back(a[i]);
    }
    build(0, 0, maxn - 1);
    for(int i = 0; i < maxn; i++) {
        for(man he : in[i]) {
            upd(0, 0, maxn - 1, he.v, he.r, 1);
        }
        pair<int, int> cur = get(0, 0, maxn - 1, i, maxn - 1);
        if(cur.X > opt) {
            opt = cur.X;
            L = i;
            R = cur.Y;
        }
        for(man he : out[i]) {
            upd(0, 0, maxn - 1, he.v, he.r, -1);
        }
    }
    cout << opt << '\n';
    if(!opt) return 0;
    for(int i = 0; i < n; i++)
        if(a[i].l <= L && L <= a[i].v && a[i].v <= R && R <= a[i].r)
            cout << i + 1 << ' ';
}
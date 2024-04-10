#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
#define set sett
const int N = 4e5 + 10;
const long long INF = 1e9 + 19;

struct Seg {
    double l, r;
    bool flag;
    Seg() { }
    Seg(double l, double r): l(l), r(r), flag(0) { }
    Seg(bool flag):flag(flag) { }
};

Seg merge(Seg w1, Seg w2) {
    if (w1.flag) return w2;
    if (w2.flag) return w1;
    double b = w2.l / (1 - (1 - w2.l) * w1.r);
    return Seg(w1.l * b, w2.r + (1 - w2.r) * w1.r * b);
}

int n, q;
double p[N];
Seg tree[N];

void build(int v, int ll, int rr) {
    if (ll + 1 == rr) {
        tree[v] = Seg(p[ll], p[ll]);
        return;
    }
    build(v * 2 + 1, ll, (ll + rr) / 2);
    build(v * 2 + 2, (ll + rr) / 2, rr);
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void set(int v, int ll, int rr, int pos, double val) {
    if (pos < ll || rr <= pos) return;
    if (ll + 1 == rr) {
        tree[v] = Seg(val, val);
        return;
    }
    set(v * 2 + 1, ll, (ll + rr) / 2, pos, val);
    set(v * 2 + 2, (ll + rr) / 2, rr, pos, val);
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

Seg get(int v, int ll, int rr, int l, int r) {
    if (l >= rr || ll >= r) return Seg(1);
    if (l <= ll && rr <= r)
        return tree[v];
    return merge(get(v * 2 + 1, ll, (ll + rr) / 2, l, r),
                 get(v * 2 + 2, (ll + rr) / 2, rr, l, r));
}

void read() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = x * 1.0 / y;
    }
}

void solve() {
    build(0, 0, n);
    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);
        if (type == 2) {
            int l, r;
            scanf("%d%d", &l, &r); l--;
            Seg res = get(0, 0, n, l, r);
            printf("%.17f\n", res.l);
        }
        else {
            int pos, a, b;
            scanf("%d%d%d", &pos, &a, &b);
            set(0, 0, n, pos - 1, a * 1.0 / b);
        }
    }

}

void stress() {

}


int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}
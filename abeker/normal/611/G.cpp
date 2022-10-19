#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> point;
#define x first
#define y second

const int MAXN = 1000005;
const int MOD = 1000000007;

int N;
point p[MAXN];
point a[MAXN], b[MAXN], c[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", &p[i].x, &p[i].y);
}

ll area(point A, point B, point C) {
    return (ll)A.x * (B.y - C.y) + (ll)B.x * (C.y - A.y) + (ll)C.x * (A.y - B.y);
}

int inc(int x) {
    return (x + 1) % N;
}

int dec(int x) {
    return (x + N - 1) % N;
}

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
    return x;
}

inline int mul(int x, int y) {
    return (ll)x * y % MOD;
}

void change(point arr[], int lo, int hi, point val) {
    arr[lo].x = add(arr[lo].x, val.x);
    arr[lo].y = add(arr[lo].y, val.y);
    arr[hi + 1].x = add(arr[hi + 1].x, -val.x);
    arr[hi + 1].y = add(arr[hi + 1].y, -val.y);
}

void update_cw(int lo, int hi, point t) {
    if (lo > hi) hi += N;
    change(a, lo, hi, point(mul(lo, t.x), -t.x));
    change(b, lo, hi, point(mul(lo, t.y), -t.y));
    change(c, lo, hi, point(lo, -1));
}

void update_ccw(int lo, int hi, point t) {
    if (lo > hi) hi += N;
    change(a, lo, hi, point(-mul(hi, t.x), t.x));
    change(b, lo, hi, point(-mul(hi, t.y), t.y));
    change(c, lo, hi, point(-hi, 1));
}

void calc(point arr[]) {
    for (int i = 1; i < MAXN; i++) {
        arr[i].x = add(arr[i].x, arr[i - 1].x);
        arr[i].y = add(arr[i].y, arr[i - 1].y);
    }
}

int eval(point t, int idx) {
    return add(t.x, mul(t.y, idx));
}

int solve() {
    ll total = 0;
    for (int i = 1; i < N - 1; i++) 
        total += area(p[0], p[i + 1], p[i]);
    
    int pos = 1;
    ll curr = 0;
    for (int i = 0; i < N; i++) {
        for (; curr < total - curr; pos = inc(pos))
            curr += area(p[i], p[inc(pos)], p[pos]);
        curr -= area(p[pos], p[inc(i)], p[i]);
        update_ccw(inc(i), pos, p[i]);
        update_cw(pos, i, p[i]);
    }
    
    calc(a);
    calc(b);
    calc(c);
    
    ll diag = (ll)N * (N - 3) / 2;
    int sol = mul((int)(diag % MOD), (int)(total % MOD));
    for (int i = 0; i < 2 * N; i++) {
        point A = p[dec(i)], B = p[i % N];
        int val_a = mul(eval(a[i], i), add(B.y, -A.y));
        int val_b = mul(eval(b[i], i), add(A.x, -B.x));
        int val_c = mul(eval(c[i], i), add(mul(B.x, A.y), -mul(A.x, B.y)));
        sol = add(sol, add(add(val_a, val_b), val_c));
    }
    
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}
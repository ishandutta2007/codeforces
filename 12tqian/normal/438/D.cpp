#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++)
#define f0r(i, a) f1r(i, 0, a)
#define trav(t, a) for (auto& t : a)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef vector<int> vi; 
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, T b) { return a > b ? a = b, 1 : 0; }

const int N = (1 << 17);

int mx[2 * N], mn[2 * N], lz[2 * N];
long long sum[2 * N];

void build() {
    for (int i = 0; i < 2 * N; i++) 
        lz[i] = -1;
}

void push(int ind, int L, int R) {
    if (lz[ind] == -1) return;
    sum[ind] = 1LL * (R - L + 1) * lz[ind];
    mx[ind] = mn[ind] = lz[ind];
    if (L != R) { 
        lz[2 * ind] = lz[2 * ind + 1] = lz[ind];
    }
    lz[ind] = -1;
}

void pull(int ind) {
    mx[ind] = max(mx[2 * ind], mx[2 * ind + 1]);
    mn[ind] = min(mn[2 * ind], mn[2 * ind + 1]);
    sum[ind] = sum[2 * ind] + sum[2 * ind + 1];
}

void upd1(int lo, int hi, int inc, int ind = 1, int L = 0, int R = N - 1) {
    push(ind, L, R);
    if (hi < L || R < lo || mx[ind] < inc) return;
    if (lo <= L && R <= hi && mx[ind] == mn[ind]) {
        lz[ind] = mn[ind] % inc;
        push(ind, L, R);
        return;
    }
    int M = (L + R) >> 1;
    upd1(lo, hi, inc, 2 * ind, L, M);
    upd1(lo, hi, inc, 2 * ind + 1, M + 1, R);
    pull(ind);
}

void upd2(int lo, int hi, int inc, int ind = 1, int L = 0, int R = N - 1) {
    push(ind, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lz[ind] = inc;
        push(ind, L, R);
        return;
    }
    int M = (L + R) >> 1;
    upd2(lo, hi, inc, 2 * ind, L, M);
    upd2(lo, hi, inc, 2 * ind + 1, M + 1, R);
    pull(ind);
}

long long query(int lo, int hi, int ind = 1, int L = 0, int R = N - 1) {
    push(ind, L, R);
    if (hi < L || R < lo) return 0;
    if (lo <= L && R <= hi) return sum[ind];
    int M = (L + R) >> 1;
    return query(lo, hi, 2 * ind, L, M) + query(lo, hi, 2 * ind + 1, M + 1, R);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    build();
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        upd2(i, i, a);
    }
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; cin >> l >> r;
            l--, r--;
            cout << query(l, r) << '\n';
        } else if (t == 2) {
            int l, r, x; cin >> l >> r >> x;
            l--, r--;
            upd1(l, r, x);
        } else {
            int k, x; cin >> k >> x;
            k--;
            upd2(k, k, x);
        }
    }
    return 0;
}
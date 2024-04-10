#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 200002;
const int MAXT = MAXN * 4;

#define Left first
#define Right second

struct TData {
    ll Left;
    ll Right;
    ll Result;
};

int n, m;
ll d[MAXN];
ll h[MAXN];
ll s[MAXN];
TData f[MAXT];
TData tmp[MAXT];

void update(TData& v, const TData& L, const TData& R, const int l, const int r, const int c)
{
    v = {
        max(L.Left, s[c] - s[l - 1] + R.Left),
        max(R.Right, s[r - 1] - s[c - 1] + L.Right),
        max(max(L.Result, R.Result), L.Right + R.Left + d[c])
    };
}

const TData& build_tree(int x, int l, int r)
{
    if (l == r) {
        f[x] = {h[l], h[l], 0};
        return f[x];
    }
    int c = (l + r) / 2;
    const TData& L = build_tree((x << 1) + 0, l, c);
    const TData& R = build_tree((x << 1) + 1, c + 1, r);
    update(f[x], L, R, l, r, c);
    //cout << " " << x << " " << l << " " << r << " " << f[x].Left << " " << f[x].Right << " " << f[x].Result << endl;
    return f[x];
}

const TData& get(int x, int l, int r, int L, int R)
{
    int c = (l + r) / 2;
    if (L <= l && r <= R) {
        return f[x];
    }

    if (R <= c) {
        return get((x << 1) + 0, l, c, L, R);
    }
    if (c < L) {
        return get((x << 1) + 1, c + 1, r, L, R);
    }

    const TData& ll = get((x << 1) + 0, l, c, L, R);
    const TData& rr = get((x << 1) + 1, c + 1, r, L, R);
    update(tmp[x], ll, rr, l, r, c);
    //cout << " " << x << " " << l << " " << r << " " << tmp[x].Left << " " << tmp[x].Right << " " << tmp[x].Result << endl;
    return tmp[x];
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    cin >> n >> m;
    //n = 1000;
    //m = 1000;
    //cout << n << " " << m << endl;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
        //d[i] = rand() % 10 + 1;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        //h[i] = rand() % 10 + 1;
    }

    /*
     *for (int i = 1; i <= n; ++i) {
     *    cout << d[i] << " ";
     *}
     *cout << endl;
     *for (int i = 1; i <= n; ++i) {
     *    cout << h[i] << " ";
     *}
     *cout << endl;
     */

    for (int i = 1; i <= n; ++i) {
        d[i + n] = d[i];
    }
    for (int i = 1; i <= n; ++i) {
        h[i] *= 2;
        h[i + n] = h[i];
    }
    d[0] = d[n];
    h[0] = h[n];
    s[0] = d[0];
    for (int i = 1; i <= 2 * n; ++i) {
        s[i] = s[i - 1] + d[i];
    }
    build_tree(1, 1, 2 * n);
    while (m--) {
        //cout << endl;
        int l, r;
        cin >> l >> r;
        /*
         *do {
         *    l = rand() % n + 1;
         *    r = rand() % n + 1;
         *} while ((l <= r && l - 1 + n - r < 2) || (l > r && l - r - 1 < 2));
         *cout << l << " " << r << endl;
         */

        if (l <= r) {
            l += n;
            swap(l, r);
        } else {
            swap(l, r);
        }

        --r;
        ++l;
        //cout << l << " " << r << endl;
        const TData& answer = get(1, 1, 2 * n, l, r);
        cout << answer.Result << "\n";

        /*
         *ll ans = 0;
         *for (int i = l; i <= r; ++i) {
         *    ll res = 0;
         *    for (int j = i + 1; j <= r; ++j) {
         *        res += d[j - 1];
         *        ans = max(ans, res + h[i] + h[j]);
         *    }
         *}
         *cout << ans << endl;
         *assert(answer.Result == ans);
         */
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
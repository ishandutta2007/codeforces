#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

const int maxn = 200500;

bool prime(int n) {
    for (int i = 2; i*i <= n; ++i) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}
vi pr;
void genpr() {
    for (int i = 2000000100; i <= 2000000900; ++i) {
        if (prime(i)) {
//             cerr << i << endl;
            pr.pb(i);
        }
    }
}

int n;
int k;
int p[maxn], q[maxn], bad[maxn];

i64 mod;
i64 norm(i64 x) { if (x >= mod) x -= mod; if (x < 0) x += mod; return x; }
i64 add(i64 x, i64 y) { x += y; if (x >= mod) x -= mod; return x; }
i64 mul(i64 x, i64 y) { return x*y%mod; }
i64 div2(i64 x) { return mul(x, (mod+1)/2); }

void scan() {
    scanf("%d%d", &n, &k);
    forn(i, n+1) scanf("%d", &p[i]);
}

void solve() {
    mod = pr.back(); pr.pop_back();
    i64 delta = 0;
    i64 x = 1;
    forn(i, n+1) {
        delta = add(delta, mul(x, norm(p[i])));
        x = mul(x, 2);
    }
    delta = norm(-delta);
//     cerr << "delta = " << delta << " (" << -mod+delta << ")" << endl;

    i64 r2 = 1;
    forn(i, n+1) {
        i64 needChange = mul(delta, r2);
        i64 neg = -mod + needChange;
        bool ok1 = abs((i64)p[i] + needChange) <= k;
        bool ok2 = abs((i64)p[i] + neg) <= k;
        assert(!(ok1 && ok2));
        if (ok1) q[i] = p[i] + needChange;
        else if (ok2) q[i] = p[i] + neg;
        else bad[i] = true;

//         if (bad[i]) cerr << "x ";
//         else cerr << q[i] << " ";

        r2 = div2(r2);
    }
//     cerr << endl;

    if (q[n] == 0) bad[n] = 1;
    forn(i, n+1) if (q[i] == p[i]) bad[i] = 1;

//     printf("%d\n", (int)count(bad, bad + n+1, 0));

// #warning
    forn(III, 5) {
        mod = pr.back();
        pr.pop_back();

        i64 delta = 0;
        i64 x = 1;
        forn(i, n+1) {
            delta = add(delta, mul(x, norm(p[i])));
            x = mul(x, 2);
        }
        delta = norm(-delta);

        x = 1;
        forn(i, n+1) {
            if (!bad[i]) {
                i64 got = mul(norm((q[i] - p[i]) % mod), x);
//                 cerr << got << " " << delta << endl;
                if (got != delta) bad[i] = true;
            }

            x = mul(x, 2);
        }
    }

    printf("%d\n", (int)count(bad, bad + n+1, 0));
}

int main() {
#ifdef HOME
    freopen("c.in", "r", stdin);
#endif

    genpr();

    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <set>
#include <map>
#include <cassert>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ());

int rnd(int x) {
    return mrand() % x;
}

void precalc() {
}

int k, a, b;

int read() {
    if (scanf("%d%d%d", &k, &a, &b) < 3) {
        return false;
    }
    return true;
}

void solve() {
    int x = a / k, y = b / k;
    if (!x && !y) {
        printf("-1\n");
        return;
    }
    if (!y) {
        swap(a, b);
        swap(x, y);
    }
    if (!x) {
        if (y * k != b) {
            printf("-1\n");
            return;
        }
    }
    printf("%d\n", x + y);
}

int main() {
    precalc();
#ifdef LOCAL
    assert(freopen(TASK ".in", "r", stdin));
    assert(freopen(TASK ".out", "w", stdout));
#endif
    while (true) {
        if (!read()) {
            break;
        }
        solve();
#ifdef DEBUG
        eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
    }
    return 0;
}
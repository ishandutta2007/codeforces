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

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn];

int read() {
    if (scanf("%d", &n) < 1) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    return true;
}

int b[maxn];

void solve() {
    int m = 0;
    for (int i = 0; i < n; i++) {
        b[i] = (a[i] == i);
        if (b[i]) {
            m++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!b[a[i]]) {
            printf("-1\n");
            return;
        }
    }
    printf("%d\n", m);
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (b[i]) {
            b[i] = pos++;
        } else {
            b[i] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", b[a[i]] + 1);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (b[i] != -1) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
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
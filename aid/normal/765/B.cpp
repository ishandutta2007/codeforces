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

int n;
string s;
char tmp[1000];

int read() {
    if (scanf("%s", tmp) < 1) {
        return false;
    }
    s = tmp;
    n = sz(s);
    return true;
}

void solve() {
    int pos = 0;
    for (int i = 0; i < n; i++) {
        int cur = s[i] - 'a';
        if (cur < pos) {
            continue;
        }
        if (cur > pos) {
            printf("NO\n");
            return;
        }
        pos++;
    }
    printf("YES\n");
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
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
string home;
map<string, int> mp;
char tmp[105];

int read() {
    if (scanf("%d", &n) < 1) {
        return false;
    }
    scanf("%s", tmp);
    home = tmp;
    return true;
}

void solve() {
    mp.clear();
    for (int i = 0; i < n; i++) {
        scanf("%s", tmp);
        string s = tmp;
        string a = s.substr(0, 3), b = s.substr(5, 3);
        if (a == home) {
            mp[b]++;
        } else {
            mp[a]--;
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second) {
            printf("contest\n");
            return;
        }
    }
    printf("home\n");
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
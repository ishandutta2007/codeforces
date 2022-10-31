#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned long ul;

template<class T> void minimize(T & x, const T & y) {
    if (y < x) x = y;
}
template<class T> void maximize(T & x, const T & y) {
    if (x < y) x = y;
}
template<class T> T sqr(T x) { return x * x; }

const ld EPS = acos(-1.0);
const int INF = (int)1e9 + 5;
const ll LINF = (ll)1e18 + 5;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int n, q;
    scanf("%d%d", &n, &q);

    int p0 = 0, p1 = 1;

    while (q--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int x;
            scanf("%d", &x);
            if (x % 2 == 0) {
                p0 = (p0 - x + n) % n;
                p1 = (p1 - x + n) % n;
            }
            else {
                int np0 = (p1 - x - 1 + n + n) % n;
                int np1 = (p0 - x + 1 + n) % n;
                p0 = np0;
                p1 = np1;
            }
        }
        else {
            swap(p0, p1);
        }
        //cerr << p0 + 1 << " " << p1 + 1 << endl;
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            int cur = (p0 + i) % n;
            p[i] = cur;
        }
        else {
            int cur = (p1 + i - 1) % n;
            p[i] = cur;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", p[i] + 1);
    }
    puts("");

    return 0;
}
#include <iostream>
#include <algorithm>
#include <map>

#define NMAX 300005
#define lsb(x) ((x) & (-(x)))
using namespace std;

int sz;

struct elem {
    int x, w, m, p;

    elem (int x = 0, int w = 0, int m = 0, int p = 0): x(x), w(w), m(m), p(p) {}
} v[NMAX];

bool operator< (const elem &a, const elem &b) {
    return a.x < b.x;
}

map <int, int> Map;

int dp[NMAX];

int aib[2 * NMAX];

inline void update (int poz, int val) {
    for (; poz <= sz; poz += lsb(poz))
        if (val > aib[poz])
            aib[poz] = val;
}

inline int query (int poz) {
    int maxim = -1;
    for (; poz; poz -= lsb(poz))
        if (aib[poz] > maxim)
            maxim = aib[poz];

    return maxim;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 1;
    cin >> n;

    for (int i = 1; i <= n; i ++) {
        cin >> v[i].x >> v[i].w;

        v[i].p = v[i].x + v[i].w;
        v[i].m = v[i].x - v[i].w;

        Map[v[i].p] = 1;
        Map[v[i].m] = 1;
    }

    sort (v + 1, v + n + 1);

    map <int, int> :: iterator it;
    int poz;
    for (it = Map.begin(), poz = 1; it != Map.end(); it++, poz ++)
        Map[it -> first] = poz;

    sz = poz;

    int maxim = 0;
    for (int i = 1; i <= n; i++) {
        v[i].p = Map[v[i].p];
        v[i].m = Map[v[i].m];

        dp[i] = 1 + query(v[i].m);
        update(v[i].p, dp[i]);

        if (dp[i] > maxim)
            maxim = dp[i];
    }

    cout << maxim << '\n';
    return 0;
}
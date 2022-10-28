#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define err(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
using namespace std;
typedef long long ll;

const int N = 2e5;

set<int> s[N];
int a[N];
int d[N];
int r[N];

int q[N];
int st = 0, en = 0;
int total;

int X[N], Y[N];
int k;

void add(int x) {
    q[en++] = x;
    a[x] = 0;
    total -= 1;
}

void bfs() {
    while (st < en) {
        int x = q[st++];
        for (int y : s[x]) if (a[y]) {
            s[y].erase(x);
            d[y] -= 1;
            if (d[y] < k) {
                add(y);
            }
        }
    }
}

int main()
{
    #ifdef amit
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    int n, m;
    scanf("%d%d%d", &n, &m, &k);
    forn(i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        X[i] = x, Y[i] = y;
        s[x].insert(y);
        s[y].insert(x);
    }
    forn(i, n) a[i] = 1, d[i] = (int)s[i].size();
    total = n;
    forn(i, n) if (d[i] < k) {
        add(i);
    }

    for (int i = m - 1; i >= 0; --i) {
        bfs();
        r[i] = total;
        int x = X[i], y = Y[i];
        if (!(a[x] && a[y])) continue;
        s[x].erase(y);
        s[y].erase(x);
        d[x]--;
        d[y]--;
        if (a[x] && d[x] < k) {
            add(x);
        }
        if (a[y] && d[y] < k) {
            add(y);
        }
    }
    forn(i, m) printf("%d\n", r[i]);



        
    return 0;
}
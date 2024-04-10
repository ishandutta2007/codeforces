#include <iostream>
#include <algorithm>

using namespace std;

#define long long long

#define M 100100

int n, e[M], m = 0;
long a[M], b[M], d[M], p[M];

long upCeil(long x, long y) {
    return (x + y - 1) / y;
}

void add(int x) {
    while (m > 0) {
        int y = e[m - 1];
        long cp = upCeil(d[x] - d[y], b[y] - b[x]);
        if (p[m - 1] >= cp)
            --m;
        else {
            p[m] = cp;
            break;
        }
    }
    e[m++] = x;
}

long get(long x) {
    int i = e[(lower_bound(p, p + m, x) - p) - 1];
    return d[i] + b[i] * x;
}

void read() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
}

void kill() {
    d[1] = 0;
    add(1);
    for (int i = 2; i <= n; ++i) {
        d[i] = get(a[i]);
        add(i);
    }
    cout << d[n] << "\n";
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout); 
#endif
    ios_base::sync_with_stdio(0);

    read();
    kill();

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int NMAX = 111;

int p[NMAX], r[NMAX];
int a[NMAX], d[NMAX];

int get(int u) {
    if (p[u] != u) {
        p[u] = get(p[u]);
    }
    return p[u];
}

void uni(int u, int v) {
    u = get(u);
    v = get(v);
    if (u != v) {
        if (r[u] == r[v]) {
            p[v] = u;
            r[u]++;
        } else if (r[u] < r[v]) {
            p[u] = v;
        } else {
            p[v] = u; 
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        r[i] = 1;
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i + d[i] <= n) {
            uni(i + d[i], i);
        }
        if (i - d[i] >= 1) {
            uni(i - d[i], i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (get(i) != get(a[i])) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
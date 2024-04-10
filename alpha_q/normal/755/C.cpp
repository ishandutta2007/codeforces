#include <bits/stdc++.h> 

using namespace std;

const int N = 1e4 + 10;

int n, p[N], par[N];
set <int> s;

int find (int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

void unite (int u, int v) {
    int x = find(u), y = find(v);
    if (x == y) return;
    par[y] = x;
}

int main (int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", p + i);
        unite(i, p[i]);
    }
    for (int i = 1; i <= n; ++i) {
        s.insert(find(i));
    }
    cout << (int) s.size() << endl;
    return 0;
}
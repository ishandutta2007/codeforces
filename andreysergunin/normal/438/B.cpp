#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
#include <queue>

#define fs first
#define sc second

using namespace std;

vector<int> p;
vector<long long> r;

int getAn(int v) {
    return (p[v] == -1 ? v : getAn(p[v]));
}

void unionSet(int u, int v) {
    if (r[u] < r[v])
        swap(u, v);
    p[v] = u;
    r[u] += r[v];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector< pair<long long, pair<int, int> > > edge(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edge[i].fs = min(a[u], a[v]);
        edge[i].sc.fs = u;
        edge[i].sc.sc = v;
    }
    
    p.resize(n);
    r.resize(n);
    
    for (int i = 0; i < n; i++) {
        p[i] = -1;
        r[i] = 1;
    }
    long long ans = 0;
    sort(edge.begin(), edge.end());
    for (int i = m - 1; i >= 0; i--) {
        int u = getAn(edge[i].sc.fs);
        int v = getAn(edge[i].sc.sc);
        if (u == v)
            continue;
        ans += 2 * edge[i].fs * r[u] * r[v];
        unionSet(u, v);
    }
    printf("%.12lf\n", (double)ans / n / (n - 1));
    return 0;
}
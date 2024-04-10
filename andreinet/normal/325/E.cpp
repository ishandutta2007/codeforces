#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int find(vector<int>& f, int x) {
    int y, p;
    for (y = f[x]; y != f[y]; y = f[y]);
    for (; x != y; x = p) {
        p = f[x];
        f[x] = y;
    }
    return y;
}

void merge(vector<int>& f, int x, int y) {
    f[find(f, x)] = find(f, y);
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    if (n % 2 == 1) {
        cout << "-1\n";
        return 0;
    }

    vector<int> prev(n), next(n);
    prev[1] = 0;
    next[0] = 1;
    prev[0] = n / 2;
    next[n / 2] = 0;

    for (int i = 1; i < n / 2; ++i) {
        next[i] = 2 * i + 1;
        prev[2 * i + 1] = i;
        next[i + n / 2] = 2 * i;
        prev[2 * i] = i + n / 2;
    }

    vector<int> f(n);
    for (int i = 0; i < n; ++i) {
        f[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        merge(f, i, next[i]);
    }
    cout << "0 ";
    int node = 1;
    while (node != 0) {
        cout << node << ' ';
        int f1 = (2 * node) % n;
        int f2 = (2 * node + 1) % n;
        int other = next[node] ^ f1 ^ f2;
        if (find(f, node) != find(f, other)) {
            int xn = next[node], xp = prev[other];
            next[node] = other;
            prev[other] = node;
            next[xp] = xn;
            prev[xn] = xp;
            merge(f, node, other);
        }
        node = next[node];
    }
    cout << "0\n";
}
#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100000 + 5;
const int MOD = 1000000000 + 9;

int father[NMAX], h[NMAX];

int find(int node) {
    if (father[node] != node) {
        father[node] = find(father[node]);
    }
    return father[node];
}

bool unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) {
        return false;
    }
    if (h[a] > h[b]) {
        swap(a, b);
    }
    father[a] = b;
    if (h[a] == h[b]) {
        ++h[b];
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
    }
    int ans = 1;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (!unite(a, b)) {
            ans = (ans * 2LL) % MOD;
        }
        cout << (ans + MOD - 1) % MOD << endl;
    }
    return 0;
}
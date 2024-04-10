#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define M 100100
#define long long long

int n;
vector<int> g[M];
int a[M], b[M];
long ans[M], l[M], sub[M];
bool used[M];

void read() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> a[i] >> b[i] >> l[i];
        g[a[i]].push_back(i);
        g[b[i]].push_back(i);
    }
}

long c3(long x) {
    return x * (x - 1) * (x - 2);
}

long dfs(int v) {
    used[v] = true;
    sub[v] = 1;

    for (int num : g[v]) {
        int to = a[num] ^ b[num] ^ v;
        if (!used[to]) {
            sub[v] += dfs(to);
            ans[num] = 2 * (c3(n) - c3(sub[to]) - c3(n - sub[to])); 
        }
    }

    return sub[v];
}

void kill() {
    ld sum = 0;
    for (int i = 1; i < n; ++i)
        sum += l[i] * ans[i];
    int q;
    long den = c3(n);
    cin >> q;
    while (q--) {
        int r, w;
        cin >> r >> w;
        sum -= l[r] * ans[r];
        l[r] = w;
        sum += l[r] * ans[r];
        cout << sum / den << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(8);
    cout << fixed;

    read();
    dfs(1);
    kill();


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 2005, Mod = 1e9 + 7;

int Father[Nmax];

int find(int x) {
    int y, p;
    for (y = x; Father[y] != y; y = Father[y]);
    for (; x != y; x = p) {
        p = Father[x];
        Father[x] = y;
    }
    return y;
}

int unite(int x, int y) {
    Father[find(x)] = find(y);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N, K, M;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; ++i)
        Father[i] = i;

    for (int i = 1; i + K - 1 <= N; ++i) {
        int left = i, right = i + K - 1;
        for (int j = 0; j < K / 2; ++j)
            unite(left + j, right - j);
    }

    int ans = 1;
    for (int i = 1; i <= N; ++i)
        if (find(i) == i)
            ans = 1LL * ans * M % Mod;

    cout << ans << '\n';
}
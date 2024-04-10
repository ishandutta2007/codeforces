#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 1005;

int n, d, u, v, par[MN], sz[MN], spare;
vector<int> a[MN];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) {spare++; return false;}
    par[x] = par[y];
    sz[y] += sz[x];
    sz[x] = 0;
    return true;
}

int32_t main() {
    boost();

    cin >> n >> d;
    for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    while (d--) {
        cin >> u >> v;
        merge(u, v);
        int ans = 0;
        vector<int> vec;
        for (int i = 1; i <= n; i++) {
            if (find(i) == i) vec.push_back(sz[i]);
        }
        sort(vec.begin(), vec.end(), greater<>());
        for (int i = 0; i < min(spare + 1, (int) vec.size()); i++) {
            ans += vec[i];
        }
        printf("%lld\n", ans - 1);
    }

    return 0;
}
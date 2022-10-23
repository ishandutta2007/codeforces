#include<bits/stdc++.h>

using namespace std;

struct UnionFind {
    vector<int> data;

    UnionFind(int sz) {
        data.assign(sz, -1);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return(false);
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return(true);
    }

    int find(int k) {
        if(data[k] < 0) return(k);
        return(data[k] = find(data[k]));
    }

    int size(int k) {
        return(-data[find(k)]);
    }
};

void solve(int n, long long p, vector<int>& a) {
    vector<int> x(n);
    for (int i = 0; i < n; ++i) x[i] = i;
    sort(x.begin(), x.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    long long ans = 0;
    long long c = n;
    auto uf = UnionFind(n);

    for (int i : x) {
        int v = a[i];
        if (v > p) break;
        if (uf.size(i) != 1) continue;
        int l = i - 1, r = i + 1;
        while (l >= 0) {
            if (a[l] % v == 0 and uf.unite(l, i)) {
                c--;
                ans += v;
            } else break;
            l--;
        }
        while (r < n) {
            if (a[r] % v == 0 and uf.unite(r, i)) {
                c--;
                ans += v;
            } else break;
            r++;
        }
    }
    ans += p * (c - 1);
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        int n, p;
        cin >> n >> p;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        solve(n, p, a);
    }
    return 0;
}
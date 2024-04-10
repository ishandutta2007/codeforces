#include <bits/stdc++.h>

using namespace std;

#define X   first
#define Y   second

long long sqr(long long x) { return x * x; }

long long solve(vector<pair<int, int>> &a, int n) {
    long long res = -1ull/2;
    sort(a.begin(), a.end());
    res = min(res, sqr(a.back().X - a.front().X));
    vector<int> sufMinY(n + 1);
    vector<int> sufMaxY(n + 1);
    for (int k = 0; k < 2; ++k) {
        reverse(a.begin(), a.end());
        for (int i = n - 1; i >= 0; --i) {
            sufMinY[i] = min(sufMinY[i + 1], a[i].Y);
            sufMaxY[i] = max(sufMaxY[i + 1], a[i].Y);
        }
        int prefMinY = 0, prefMaxY = 0;
        for (int i = 0, j = n - 1; i <= j; ++i) {
            for (; i < j && abs(a[i].X) < abs(a[j].X); --j);
            int lo = i, hi = j;
            for (; lo <= hi; ) {
                int k = (lo + hi) / 2;
                int minY = min(prefMinY, sufMinY[k + 1]);
                int maxY = max(prefMaxY, sufMaxY[k + 1]);
                int absY = max(maxY, -minY);
                auto d1 = sqr(a[i].X - a[k].X);
                auto d2 = sqr(maxY - minY);
                auto d3 = sqr(a[i].X) + sqr(absY);
                res = min(res, max(d1, max(d2, d3)));
                d1 > d3 ? hi = k - 1 : lo = k + 1;
            }
            prefMinY = min(prefMinY, a[i].Y);
            prefMaxY = max(prefMaxY, a[i].Y);
        }
    }
    int lo = 0, hi = sqrt(res);
    for (; lo <= hi; ) {
        int k = (lo + hi) / 2;
        auto maxH = sqr(k);
        bool ok = false;
        int prefMinY = 0, prefMaxY = 0;
        for (int i = 0, j = 0; j < n; ++j) {
            for (; a[j].X - a[i].X > k; ++i) {
                prefMinY = min(prefMinY, a[i].Y);
                prefMaxY = max(prefMaxY, a[i].Y);
            }
            int minY = min(prefMinY, sufMinY[j + 1]);
            int maxY = max(prefMaxY, sufMaxY[j + 1]);
            int absY = max(maxY, -minY);
            auto bad = sqr(maxY - minY);
            bad = max(bad, sqr(absY) + sqr(max(abs(a[i].X), abs(a[j].X))));
            if (bad <= maxH) {
                ok = true;
                break;
            }
        }
        ok ? hi = k - 1 : lo = k + 1;
    }
    res = min(res, sqr(lo));
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> a(n);
    for (auto &p : a)
        scanf("%d%d", &p.X, &p.Y);
    long long res = solve(a, n);
    for (auto &p : a) swap(p.X, p.Y);
    res = min(res, solve(a, n));
    cout << res << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

#define x first
#define y second
#define int long long

ld dist(pair<int, int> a, pair<int, int> b) {
    return sqrt((ld)(a.x-b.x)*(a.x-b.x) + (ld)(a.y-b.y)*(a.y-b.y));
}

struct L {
    ll a, b, c;
    pair<int, int> any;

    L() = default;
    L(pair<int, int> a, pair<int, int> b) : a(a.y - b.y), b(b.x - a.x), c(a.x * b.y - a.y * b.x), any(a) {}

    ll eval(pair<int, int> p) const {
        return a * p.x + b * p.y + c;
    }
};

pair<int, int> operator - (pair<int, int> a, pair<int, int> b) {
    return { a.x - b.x, a.y - b.y };
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    --k;
    vector<pair<int, int>> a(n);
    for (auto& p : a) {
        cin >> p.x >> p.y;
    }

    if (n <= 4) {
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        ld ans = 1e18 + 228;
        do {
            if (ord[0] != k) {
                continue;
            }
            ld cur = 0;
            for (int i = 0; i < n - 1; i++) {
                cur += dist(a[ord[i]], a[ord[i + 1]]);
            }
            ans = min(ans, cur);
        } while (next_permutation(ord.begin(), ord.end()));
        cout << ans << endl;
        return 0;
    }

    L base{};
    bool kok = false;
    for (int i = 0; i < 3 && !kok; i++) {
        for (int j = i + 1; j < 3 && !kok; j++) {
           L l(a[i], a[j]);
           int cnt = 0;
           for (int z = 0; z < n; z++) {
               cnt += (l.eval(a[z]) == 0);
           }
           if (cnt == n - 1) {
               kok = true;
               base = l;
           }
        }
    }
    assert(kok);

    int out = 0;
    while (base.eval(a[out]) == 0) {
        out++;
    }

    vector<pair<int, int>> kek;
    for (int i = 0; i < n; i++) {
        if (i != out) {
            kek.emplace_back(a[i]);
        }
    }
    sort(kek.begin(), kek.end());

    if (out == k) {
        cout << dist(kek[0], kek[n - 2]) + min(dist(kek[0], a[out]), dist(kek[n - 2], a[out])) << endl;
        return 0;
    }

    int pos = 0;
    while (kek[pos] != a[k]) {
        pos++;
    }

    kek.insert(kek.begin(), kek[0]);
    kek.emplace_back(kek.back());
    pos++;

    ld ans = 1e18 + 228;
    ans = min(ans, dist(kek[pos], kek[1]) + dist(kek[1], a[out]) + min(dist(a[out], kek[pos + 1]), dist(a[out], kek.back())) + dist(kek[pos + 1], kek.back()));
    ans = min(ans, dist(kek[pos], kek.back()) + dist(kek.back(), a[out]) + min(dist(a[out], kek[pos - 1]), dist(a[out], kek[0])) + dist(kek[pos - 1], kek[0]));

    ans = min(ans, dist(kek[pos], a[out]) + min(dist(a[out], kek[0]), dist(a[out], kek.back())) + dist(kek[0], kek.back()));

    ans = min(ans, dist(kek[pos], kek[0]) + dist(kek[0], kek.back()) + dist(kek.back(), a[out]));
    ans = min(ans, dist(kek[pos], kek.back()) + dist(kek[0], kek.back()) + dist(kek[0], a[out]));

    ld full = dist(kek[0], kek.back());
    for (int i = 0; i < (int) kek.size() - 1; i++) {
        ans = min(ans, min(dist(kek[pos], kek[0]), dist(kek[pos], kek.back())) + full - dist(kek[i], kek[i + 1]) + dist(kek[i], a[out]) + dist(kek[i + 1], a[out]));
    }

    cout << ans << endl;
    cout.flush();
    return 0;
}
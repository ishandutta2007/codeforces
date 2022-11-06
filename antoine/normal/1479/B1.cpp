#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


struct DS {
    DS(int x) : x(x) { a[0] = a[1] = x; }

    int x;
    int a[2];

    bool ok() {
        return a[0] != x && a[1] != x;
    }

    void f(int y) {
        if (ok())
            return;
        if (a[1] == x)
            swap(a[0], a[1]);

        if (y != a[0])
            a[0] = y;
        else {
            assert(y != a[1]);
            a[1] = y;

        }
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int n;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (!v.empty() && v.back().first == x)
            v.back().second = 2;
        else
            v.emplace_back(x, 1);
    }
    int ans = 0;
    for (auto e : v)
        ans += e.second;
    n = v.size();
    for (int i = 0; i < n; ++i) {
        assert(1 <= v[i].second && v[i].second <= 2);
        if (v[i].second != 2)
            continue;
        int j = i + 1;
        while (j < n && v[j].second != 2)
            ++j;
        if (j == n || v[i].first != v[j].first)
            continue;
        DS ds(v[i].first);
        for (int k = i + 1; k < j; ++k)
            ds.f(v[k].first);
        ans -= !ds.ok();
    }
    cout << ans;
    return 0;
}
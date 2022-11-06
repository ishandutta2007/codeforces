#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

vector<int> g[555];

int d[555];

void dfs(int v, int p) {
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        d[i] = d[v] + 1;
        dfs(i, v);
    }
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        s += a[i].first;
    }

    if (s < 2 * (n - 1)) {
        cout << "NO\n";
        return 0;
    }

    sort(rbegin(a), rend(a));
    while (isz(a) > 2 && a[a.size() - 3].first == 1) {
        g[a.back().second].push_back(a[0].second);
        g[a[0].second].push_back(a.back().second);
        a.pop_back();
        a[0].first--;
        sort(rbegin(a), rend(a));
    }

    sort(begin(a), end(a));
    swap(a[1], a.back());
    for (int i = 0; i + 1 < isz(a); i++) {
        int x = a[i].second;
        int y = a[i + 1].second;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, -1);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] > d[mx]) {
            mx = i;
        }
    }
    d[mx] = 0;
    dfs(mx, -1);
    cout << "YES " << *max_element(d, d + n) << "\n";
    cout << n - 1 << "\n";
    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            if (i < j) {
                cout << i + 1 << " " << j + 1 << "\n";
            }
        }
    }

    return 0;
}//lqhfbv
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

bool f(vector<pair<int, int>> a, vector<pair<int, int>> b) {
    sort(a.begin(), a.end());
    int x1 = a[0].first;
    int y1 = a[0].second;
    int x2 = a.back().first;
    int y2 = a.back().second;

    sort(b.begin(), b.end());
    b.emplace_back((b.front().first + b.back().first) / 2, (b[1].second + b[2].second) / 2);

    for (auto& p : b) {
        int x = p.first;
        int y = p.second;
        if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
            return true;
        }
    }

    return false;
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<pair<int, int>> a(4);
    for (int i = 0; i < 4; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first *= 2;
        a[i].second *= 2;
    }

    vector<pair<int, int>> b(4);
    for (int i = 0; i < 4; i++) {
        cin >> b[i].first >> b[i].second;
        b[i].first *= 2;
        b[i].second *= 2;
    }

    if (f(a, b)) {
        cout << "YES\n";
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        auto p = a[i];
        a[i] = {p.first + p.second, p.first - p.second};
    }

    for (int i = 0; i < 4; i++) {
        auto p = b[i];
        b[i] = {p.first + p.second, p.first - p.second};
    }

    if (f(b, a)) {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";

    return 0;
}//lwdawt
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i + 1 < n; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> used(n);
    queue<set<int>> q;
    q.push({0});
    used[0] = 1;
    while (!q.empty()) {
        set<int> s = q.front();
        q.pop();
        while (!s.empty()) {
            int v;
            cin >> v;
            --v;
            if (s.find(v) == s.end()) {
                cout << "No";
                return 0;
            }
            s.erase(v);
            set<int> nx;
            for (int i : g[v]) {
                if (!used[i]) {
                    used[i] = 1;
                    nx.insert(i);
                }
            }
            if (!nx.empty()) {
                q.push(nx);
            }
        }
    }

    cout << "Yes";

    return 0;
}//btkbof
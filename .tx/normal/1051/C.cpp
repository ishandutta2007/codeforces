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
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[x].push_back(i);
    }
    map<int, vector<int>> cnt;
    for (auto& p : m) {
        cnt[(int) p.second.size()].push_back(p.first);
    }

    vector<int> ans(n, 0);

    if (cnt[1].size() % 2 == 0) {
        for (int i = 0; i < cnt[1].size(); i += 2) {
            ans[m[cnt[1][i]][0]] = 1;
        }
    } else {
        int x = -1;
        for (auto& p : cnt) {
            if (p.first > 2 && p.second.size() > 0) {
                x = p.first;
                break;
            }
        }
        if (x == -1) {
            cout << "NO";
            return 0;
        }
        for (int i = 1; i < cnt[1].size(); i += 2) {
            ans[m[cnt[1][i]][0]] = 1;
        }
        ans[m[cnt[x][0]][0]] = 1;
    }

    cout << "YES\n";
    for (int i : ans) {
        cout << char(i + 'A');
    }

    return 0;
}//dwjeeo
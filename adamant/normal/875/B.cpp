#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

#define int int64_t

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    set<int> lol;
    cout << 1 << " ";
    int used[n + 1] = {0};
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        lol.insert(a[i]);
        while(lol.size() && (*prev(end(lol)) == n || used[*prev(end(lol)) + 1])) {
            used[*prev(end(lol))] = 1;
            lol.erase(prev(end(lol)));
        }
        cout << 1 + lol.size() << " ";
    }
    return 0;
}
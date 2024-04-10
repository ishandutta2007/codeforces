#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    pi ans(-1, -1);
    vector<pi> v;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        v.emplace_back(min(x, y), max(x, y));
    }
    sort(v.begin(), v.end());
    for (int i = 0, now = 0; i < n; ++i) for (int j = i + 1; j < n; ++j, ++now) {
        if (now >= v.size() || v[now] != make_pair(i, j)) {
            ans = make_pair(i, j);
            goto out;
        }
    }
    return cout << "NO", 0;
    out :
    cout << "YES\n";
    int now = 3;
    for (int i = 0; i < n; ++i)
        cout << (i == ans.first ? 1 : i == ans.second ? 2 : now++) << ' ';
    cout << '\n';
    now = 3;
    for (int i = 0; i < n; ++i)
        cout << (i == ans.first ? 1 : i == ans.second ? 1 : now++) << ' ';
}
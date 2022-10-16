#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5;
pair<pair<int, int>, int> e[MAXN];
pair<int, int> ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> e[i].first.first >> e[i].first.second;
        e[i].first.second ^= 1;
        e[i].second = i;
    }
    sort(e, e + m);
    int v = 0, need = m - n + 1;
    vector< pair<int, int> > ee;
    for(int i = 0; i < m; i++)
        if(e[i].first.second == 0) {
            ans[e[i].second] = make_pair(v, v + 1);
            for(int u = 0; u < v && (int)ee.size() < need; u++)
                ee.push_back(make_pair(u, v + 1));
            v++;
        }
        else {
            if(ee.empty()) {
                cout << -1 << '\n';
                return 0;
            }
            ans[e[i].second] = ee.back();
            ee.pop_back();
            need--;
        }
    for(int i = 0; i < m; i++)
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    return 0;
}
#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    multiset<pair<int, int>> a[4];
    vector<int> cost(n), c1(n), c2(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c2[i];
    }
    for (int i = 0; i < n; ++i) {
        a[c1[i]].insert(make_pair(cost[i], i));
        a[c2[i]].insert(make_pair(cost[i], i));
    }
    int m;
    cin >> m;
    vector<bool> used(n, false);
    while (m-- > 0) {
        int x;
        cin >> x;

        int price = -1;
        while (price == -1 && !a[x].empty()) {
            int index = a[x].begin()->second;
            int cprice = a[x].begin()->first;
            a[x].erase(a[x].begin());
            if (!used[index]) {
                used[index] = true;
                price = cprice;
            }
        }
        cout << price << ' ';
    }
    cout << '\n';
}
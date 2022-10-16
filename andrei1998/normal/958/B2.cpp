#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<set<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; cin >> x >> y; --x; --y;
        tree[x].insert(y);
        tree[y].insert(x);
    }

    priority_queue<pair<int, int>> bfq;
    for (int i = 0; i < n; ++i) {
        if ((int)tree[i].size() == 1) {
            bfq.emplace(-1, i);
        }
    }

    vector<int> result(n);
    fill(result.begin() + bfq.size() - 1, result.end(), n);
    result[0] = 1;

    int where = (int)bfq.size() - 2;
    while (where > 0) {
        int node, steps;
        tie(steps, node) = bfq.top();
        bfq.pop();

        int parent = *tree[node].begin();

        tree[parent].erase(node);
        if ((int)tree[parent].size() == 1) {
            bfq.emplace(steps - 1, parent);
        } else {
            result[where] = result[where + 1] + steps;
            --where;
        }
    }

    for (auto it : result) {
        cout << it << ' ';
    }
    cout << '\n';

    return 0;
}
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

    vector<vector<int>> graph(n);
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        x--;
        graph[x].push_back(i);
        graph[i].push_back(x);
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || SZ(graph[i]) != 1) {
            int cnt = 0;
            for (int to: graph[i]) {
                if (SZ(graph[to]) == 1) {
                    cnt++;
                }
            }
            ok &= cnt >= 3;
        }
    }
    cout << (ok ? "Yes\n": "No\n");
}
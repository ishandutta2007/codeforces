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

    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    vector<bool> used(n, false);
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ans++;
            queue<int> q;
            used[i] = true;
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int to = 0; to < n; ++to) {
                    if (!used[to] && (x[node] == x[to] || y[node] == y[to])) {
                        used[to] = true;;
                        q.push(to);
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
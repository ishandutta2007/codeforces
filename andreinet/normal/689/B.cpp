#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

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
    vector<int> A(n);
    for (int& p: A) {
        cin >> p;
        --p;
    }
    vector<int> dist(n, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node > 0 && dist[node - 1] == -1) {
            dist[node - 1] = dist[node] + 1;
            q.push(node - 1);
        }
        if (node < n - 1 && dist[node + 1] == -1) {
            dist[node + 1] = dist[node] + 1;
            q.push(node + 1);
        }
        if (dist[A[node]] == -1) {
            dist[A[node]] = dist[node] + 1;
            q.push(A[node]);
        }
    }

    for (int d: dist) {
        cout << d << ' ';
    }
    cout << '\n';
}
#include <bits/stdc++.h>

using namespace std;

#define M 100100

int a[M], n, t;
bool used[M];

int main() {
    cin >> n >> t;
    for (int i = 1; i < n; ++i)
        cin >> a[i];

    queue<int> q;
    q.push(1);
    used[1] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int to = x + a[x];
        if (!used[to]) {
            q.push(to);
            used[to] = true;
        }
    }

    cout << (used[t] ? "YES\n" : "NO\n");
    return 0;
}
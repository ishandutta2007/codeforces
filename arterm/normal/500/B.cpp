#include <bits/stdc++.h>

using namespace std;

#define M 404

bool a[M][M];
int n, p[M], ans[M];
bool used[M];

void bfs(int x) {
    queue<int> q;
    vector<int> v;
    used[x] = true;
    q.push(x);
    v.push_back(x);

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i)
            if (a[x][i] && !used[i]) {
                used[i] = true;
                q.push(i);
                v.push_back(i);
            }
    }

    vector<int> s(v);
    for (int &x : s)
        x = p[x];

    sort(v.begin(), v.end());
    sort(s.begin(), s.end());

    for (int i = 0; i < (int) v.size(); ++i)
        ans[v[i]] = s[i];
}

int main() {
    cin >> n; 
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            char ch;
            cin >> ch;
            a[i][j] = (ch == '1');
        }

    for (int i = 1; i <= n; ++i)
        if (!used[i])
            bfs(i);

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}
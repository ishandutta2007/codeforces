#include <bits/stdc++.h>

using namespace std;

const int M = 500500;
const int INF = 1000000000;

int n, m, a[M], f[M], ans[M];
map<int, int> last;
vector<int> q[M], num[M];

void ini() {
    fill(f, f + M, INF);
}

void upd(int at, int val) {
    for (int i = at; i < M; i |= i + 1)
        f[i] = min(f[i], val);
}

int get(int x) {
    int ans = INF;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        ans = min(ans, f[i]);
    return ans;
}

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1, l, r; i <= m; ++i) {
        scanf("%d%d", &l, &r);
        q[l].push_back(r);
        num[l].push_back(i);
    }
}

void kill() {
    ini();
    for (int i = n; i >= 1; --i) {
        if (last.count(a[i]) > 0) {
            upd(last[a[i]], last[a[i]] - i);
        }
        last[a[i]] = i;

        for (int j = 0; j < (int) q[i].size(); ++j) {
            int x = get(q[i][j]);
            if (x == INF)
                x = -1;
            ans[num[i][j]] = x;
        }
    }

    for (int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);
}

int main() {
    read();
    kill();
    return 0;
}
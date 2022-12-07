#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 20003;
const int MAX = 1e9;
int L[N], R[N];
int n1, n2;
char ss[N];
int n;
int a[N];
int ans[N];
bool check() {
    if (n1 < n2)
        return true;
    if (n1 > n2)
        return false;
    for (int u = 1; u <= n1; u++) {
        if (L[u] > R[u])
            return false;
        if (L[u] < R[u])
            return true;
    }
    return true;
}
int son[N][10], num, sum[N][2005], fail[N];
void dfs(int now, bool tf, bool tf1, int x) {
    if (tf == false && tf1 == false) {
        sum[x][n2 - now + 1] = 1;
        return;
    }
    if (now > n2) {
        sum[x][0] = 1;
        return;
    }
    int l, r;
    if (tf1 == true)
        l = L[now];
    else
        l = 0;
    if (tf == true)
        r = R[now];
    else
        r = 9;
    for (int u = l; u <= r; u++) {
        int y;
        if (x == 0 && u == 0)
            y = x;
        else {
            if (son[x][u] == 0)
                son[x][u] = ++num;
            y = son[x][u];
        }
        dfs(now + 1, tf & (u == R[now]), tf1 & (u == L[now]), y);
    }
}
void Bt() {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int u = 0; u <= 9; u++) {
            int t = son[x][u], ff = fail[x];
            if (t != 0) {
                if (x == 0)
                    fail[t] = 0;
                else
                    fail[t] = son[ff][u];
                for (int i = 0; i <= n; i++) sum[t][i] += sum[fail[t]][i];
                q.push(t);
            } else
                son[x][u] = son[ff][u];
        }
    }
}
int f[2005][N];
int from[2005][N];
void DP() {
    for (int u = 0; u <= num; u++)
        for (int i = 1; i <= n; i++) {
            sum[u][i] = sum[u][i] + sum[u][i - 1];
            // printf("%d %d %d\n",u,i,sum[u][i]);
        }
    for (int u = 0; u <= num; u++) f[0][u] = sum[u][0];
    for (int u = 1; u <= n; u++)
        for (int i = 0; i <= num; i++) {
            f[u][i] = -MAX;
            for (int j = 0; j <= 9; j++) {
                int y = son[i][j];
                if (f[u][i] < f[u - 1][y]) {
                    from[u][i] = j;
                    f[u][i] = f[u - 1][y];
                }
            }
            f[u][i] = f[u][i] + sum[i][u];
        }
    printf("%d\n", f[n][0]);
    int now = 0;
    for (int u = n; u >= 1; u--) {
        printf("%d", from[u][now]);
        now = son[now][from[u][now]];
    }
}
int main() {
    scanf("%s", ss + 1);
    n1 = strlen(ss + 1);
    for (int u = 1; u <= n1; u++) L[u] = ss[u] - '0';
    scanf("%s", ss + 1);
    n2 = strlen(ss + 1);
    for (int u = 1; u <= n2; u++) R[u] = ss[u] - '0';
    int d = n2 - n1;
    for (int u = n1; u >= 1; u--) L[u + d] = L[u];
    for (int u = d; u >= 1; u--) L[u] = 0;
    dfs(1, true, true, 0);
    scanf("%d", &n);
    Bt();
    DP();
    return 0;
}
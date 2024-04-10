#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1024

struct op {
    int v1, v2, v3, v4;
};

int n, i, x, y;
bool adj[maxN][maxN];
vector<op> to, from;


void solve(vector<op>& data) {
    int i, j, k;

    for (i = 2; adj[1][i + 1] == true; i++);
    if (i == n) return;
    for (j = i + 1; adj[1][j] == false; j++);

    for (k = 2; adj[i][k] == false || adj[j][k] == false; k++);
    data.pb({i, j, 1, k});

    adj[i][j] = adj[j][i] = false;
    adj[1][k] = adj[k][1] = true;
    solve(data);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);

    for (i = 1; i < n; i++) adj[i][i + 1] = adj[i + 1][i] = true;
    adj[1][n] = adj[n][1] = true;
    for (i = 1; i <= n - 3; i++) {
        scanf("%d%d", &x, &y);
        adj[x][y] = adj[y][x] = true;
    }
    solve(to);

    memset(adj, 0, sizeof(adj));
    for (i = 1; i < n; i++) adj[i][i + 1] = adj[i + 1][i] = true;
    adj[1][n] = adj[n][1] = true;
    for (i = 1; i <= n - 3; i++) {
        scanf("%d%d", &x, &y);
        adj[x][y] = adj[y][x] = true;
    }
    solve(from);

    reverse(from.begin(), from.end());
    printf("%d\n", to.size() + from.size());
    for (auto e : to) printf("%d %d\n", e.v1, e.v2);
    for (auto e : from) printf("%d %d\n", e.v3, e.v4);


    return 0;
}
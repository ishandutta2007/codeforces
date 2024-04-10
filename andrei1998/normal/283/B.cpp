#include <bits/stdc++.h>

using namespace std;

const int NMAX = 200000 + 5;
typedef long long int lint;

int N, a[NMAX];

tuple <lint, int, int> memo[NMAX][2]; // (sum, where, moves)
bool vis[NMAX][2];
bool bad[NMAX][2];

tuple <lint, int, int> dfs(int node, bool parity) {
    if (node < 1)
        node = -1;
    if (node <= 1 || node > N)
        return make_tuple(0, node, 0);
    if (vis[node][parity])
        return memo[node][parity];

    vis[node][parity] = true;
    if (bad[node][parity])  {
        memo[node][parity] = make_tuple(-1, -2, 0);
        return memo[node][parity];
    }

    int sign = 1;
    if (parity == true)
        sign = -1;
    const int newPos = node + sign * a[node];
    const auto it = dfs(newPos, parity ^ 1);

    if (get<1>(it)== -2)
        memo[node][parity] = make_tuple(-1, -2, 0);
    else
        memo[node][parity] = make_tuple(get<0>(it) + a[node], get<1>(it), 1 + get<2>(it));
    return memo[node][parity];
}

int edges[NMAX][2];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("data.in", "r", stdin);

    cin >> N;
    for (int i = 2; i <= N; ++ i)
        cin >> a[i];

    queue <pair <int, bool> > q;
    for (int i = 2; i <= N; ++ i) {
        int where = i;
        if (2 <= where - a[i] && where - a[i] <= N)
            ++ edges[where - a[i]][0];
        if (2 <= where + a[i] && where + a[i] <= N)
            ++ edges[where + a[i]][1];
    }

    for (int i = 2; i <= N; ++ i)
        for (int j = 0; j < 2; ++ j)
            if (!edges[i][j])
                q.push(make_pair(i, j));

    while (!q.empty()) {
        pair <int, bool> node = q.front();
        q.pop();

        const int where = node.first;
        int sign = 1;
        const int parity = node.second;
        if (node.second == true)
            sign = -1;
        if (2 <= where + sign * a[where] && where + sign * a[where] <= N) {
            const int newPos = where + sign * a[where];
            -- edges[newPos][parity ^ 1];
            if (edges[newPos][parity ^ 1] == 0)
                q.push(make_pair(newPos, parity ^ 1));
        }
    }

    for (int i = 2; i <= N; ++ i)
        for (int j = 0; j < 2; ++ j)
            if (edges[i][j])
                bad[i][j] = true;

    for (int i = 1; i < N; ++ i) {
        auto it = dfs(1 + i, 1);
        lint sum;
        int where, moves;
        tie(sum, where, moves) = it;
        sum += i;
        moves ++;

        if (where == 1) {
            if (moves % 2 == 0)
                cout << "-1\n";
            else {
                cout << sum + i << '\n';
            }
        }
        else if (where == -2)
            cout << "-1\n";
        else
            cout << sum << '\n';
    }

    return 0;
}
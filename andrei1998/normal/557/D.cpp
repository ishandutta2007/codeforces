#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf (1 << 30)
using namespace std;

bool vis[100005];

vector <int> graph[100005];
bool h[100005];
int sz[100005];

int zeroes[2];
bool done;

void dfs (int node) {
    vis[node] = true;
    sz[node] = 1;

    zeroes[h[node] == 1] ++;

    for (auto it: graph[node])
        if (!vis[it]) {
            h[it] = (1 ^ h[node]);
            dfs(it);

            sz[node] += sz[it];
        }
        else if (!(h[node] ^ h[it]))
            done = true;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0, m = 0;
    cin >> n >> m;

    if (!m) {
        cout << "3 " << (n * (n - 1ll) * (n - 2ll)) / 6ll << endl;
        return 0;
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool sunt_mari = false;

    long long int all_sols = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            zeroes[0] = zeroes[1] = 0;
            dfs(i);

            if (sz[i] > 2)
                sunt_mari = true;
            all_sols += (1ll * zeroes[0] * (zeroes[0] - 1ll) / 2ll + 1ll * zeroes[1] * (zeroes[1] - 1ll) / 2ll);
        }

    if (done) {
        cout << "0 1\n";
        return 0;
    }

    if (!sunt_mari) {
        cout << "2 " << m * (n - 2ll) << endl;
        return 0;
    }

    cout << "1 " << all_sols << endl;
    return 0;
}
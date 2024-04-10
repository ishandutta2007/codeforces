#include <iostream>
#include <algorithm>
#include <vector>

#define lint long long int
using namespace std;

bool is_gov[1005];

vector <int> norm;
vector <int> gov;

vector <int> graph[1005];
int sz;
bool has_gov;
bool vis[1005];

void dfs(int node) {
    ++ sz;
    vis[node] = true;
    if (is_gov[node])
        has_gov = true;

    for (auto it: graph[node])
        if (!vis[it])
            dfs(it);
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    for (int i = 1; i <= k; ++ i) {
        int x;
        cin >> x;
        is_gov[x] = true;
    }
    
    for (int i = 1; i <= m; ++ i) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; ++ i)
        if (!vis[i]) {
            sz = 0;
            has_gov = false;
            dfs(i);

            if (has_gov)
                gov.push_back(sz);
            else
                norm.push_back(sz);
        }

    sort(gov.begin(), gov.end(), greater<int>());

    for (int i = 0; i < norm.size(); ++ i)
        gov[0] += norm[i];

    lint ans = -m;
    for (auto it: gov) {
        ans += (it * (it - 1LL)) / 2;
    }

    cout << ans << '\n';
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 1000000 + 5;

int N, M;
vector <int> graph[NMAX];
int sz[NMAX];

bool vis[NMAX];
int cnt;
void dfs(int node) {
    vis[node] = true, ++ cnt;
    for (auto it: graph[node])
        if (!vis[it])
            dfs(it);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int isolated = N;
    int bonus = 0;
    for (int i = 1; i <= M; ++ i) {
        int a, b;
        cin >> a >> b;

        if (graph[a].empty())
            isolated --;
        graph[a].push_back(b);
        ++ sz[a];
        if (a != b) {
            ++ sz[b];
            if (graph[b].empty())
                isolated --;
            graph[b].push_back(a);
        }
        else {
            -- sz[a];
            ++ bonus;
        }
    }

    cnt = 1;
    for (int i = 1; i <= N; ++ i)
        if (!graph[i].empty()) {
            cnt = 0;
            dfs(i);
            break;
        }
    if (cnt != N - isolated) {
        cout << "0\n";
        return 0;
    }

    long long int ans = 0;
    for (int i = 1; i <= N; ++ i)
        ans += sz[i] * (sz[i] - 1LL) / 2;

    ans += 1LL * bonus * (M - bonus);
    ans += 1LL * bonus * (bonus - 1LL) / 2;

    cout << ans << '\n';
    return 0;
}
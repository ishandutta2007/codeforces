#include <iostream>
#include <algorithm>
#include <vector>

#define lint long long int
using namespace std;

const int NMAX = 30 + 5;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N;
vector <int> graph[NMAX];

pair <lint, lint> points[NMAX];

void twice() {
    for (int i = 1; i <= N; ++ i) {
        points[i].first *= 2LL;
        points[i].second *= 2LL;
    }
}

void dfs(int node, int father, int dir) {
    vector <int> dirs = {0, 1, 2, 3};
    if (dir >= 0)
        dirs.erase(find(dirs.begin(), dirs.end(), dir));

    for (auto it: graph[node])
        if (it != father) {
            dir = dirs.back();
            dirs.pop_back();

            twice();
            points[it] = {points[node].first + dx[dir], points[node].second + dy[dir]};
            dfs(it, node, dir ^ 1);
        }
}

int main()
{
    cin >> N;
    for (int i = 1; i < N; ++ i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; ++ i)
        if (graph[i].size() > 4) {
            cout << "NO\n";
            return 0;
        }

    points[1] = {1000, 1000};

    dfs(1, 0, -1);

    cout << "YES\n";
    for (int i = 1; i <= N; ++ i)
        cout << points[i].first << ' ' << points[i].second << '\n';
    return 0;
}
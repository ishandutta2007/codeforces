#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1000 + 5;
int N;
vector <set <int> > oldSets[NMAX];
vector <set <int> > Sets[NMAX];

vector <pair <int, int> > sol;
vector <int> graph[NMAX];

bool vis[NMAX];
void dfs1(int node) {
    vis[node] = true;
    for (auto it: graph[node])
        if (!vis[it])
            dfs1(it);
}
bool connected() {
    dfs1(1);
    for (int i = 1; i <= N; ++ i)
        if (!vis[i])
            return false;
    return true;
}
bool erased[NMAX];

set <int> vvv;
void dfs2(int node, int father) {
    vvv.insert(node);
    for (auto it: graph[node])
        if (it != father)
            dfs2(it, node);
}

void build(int node, vector <set <int> > &Set) {
    for (auto it: graph[node]) {
        vvv.clear();
        dfs2(it, node);
        Set.push_back(vvv);
    }
}

int main()
{
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    int sumCnt = 0;
    for (int i = 1; i <= N; ++ i) {
        int x = 0;
        bool first = true;
        while (1) {
            if (!first) { char ch; cin >> ch; } else first = false;
            ++ sumCnt;
            int cnt = 0;
            cin >> cnt;
            x += cnt;
            Sets[i].push_back(set <int>());
            for (int j = 1; j <= cnt; ++ j) {
                char ch;
                cin >> ch;
                int node;
                cin >> node;
                Sets[i].back().insert(node);
            }

            if (x == N - 1)
                break;
        }
    }

    for (int i = 1; i <= N; ++ i)
        oldSets[i] = Sets[i];

    if (sumCnt != 2 * N - 2) {
        cout << "-1\n";
        return 0;
    }

    bool done = false;
    while (!done) {
        done = true;
        int node = -1;
        for (int i = 1; i <= N && done; ++ i) if (!erased[i]) {
            for (const auto &it: Sets[i])
                if (it.size() == 1) {
                    node = *it.begin();
                    sol.push_back({i, node});
                    erased[node] = true;
                    done = false;
                    break;
                }
        }

        if (node != -1)
            for (int i = 1; i <= N; ++ i)
                for (auto &it: Sets[i])
                    it.erase(node);
    }

    if (sol.size() != N - 1) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= N; ++ i)
        Sets[i].clear();

    for (auto it: sol) {
        graph[it.first].push_back(it.second);
        graph[it.second].push_back(it.first);
    }

    if (!connected()) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= N; ++ i)
        build(i, Sets[i]);

    for (int i = 1; i <= N; ++ i) {
        sort(oldSets[i].begin(), oldSets[i].end());
        sort(Sets[i].begin(), Sets[i].end());
        if (oldSets[i] != Sets[i]) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << N - 1 << '\n';
    for (auto it: sol)
        cout << it.first << ' ' << it.second << '\n';
    return 0;
}
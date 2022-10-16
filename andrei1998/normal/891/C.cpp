#include <bits/stdc++.h>

using namespace std;

const int NMAX = 5 * 100000 + 5;

int N, M;

struct Edge {
    int a, b, c;
} edges[NMAX];

int father[NMAX];
int h[NMAX];
static inline void init() {
    for (int i = 1; i <= N; ++ i)
        father[i] = i, h[i] = 0;
}
int find(int node) {
    if (father[node] != father[father[node]])
        father[node] = find(father[node]);
    return father[node];
}
static inline void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
        return ;
    if (h[a] > h[b])
        swap(a, b);
    if (h[a] == h[b])
        ++ h[b];
    father[a] = b;
}

bool queryOk[NMAX];

//int cntEdgesInFinal[NMAX];
vector <int> edgesHere[NMAX];
vector <pair <vector <int>, int> > queriesHere[NMAX];

int ord[NMAX];

bool vis[NMAX];
vector <pair <int, int> > graph[NMAX];

bool hasCycle;
void dfs(int node, int father) {
    vis[node] = true;
    for (auto it: graph[node])
        if (!vis[it.first])
            dfs(it.first, it.second);
        else if (it.second != father)
            hasCycle = true;
}

int main()
{
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    init();
    for (int i = 1; i <= M; ++ i)
        cin >> edges[i].a >> edges[i].b >> edges[i].c;

    //Do queries
    for (int i = 1; i <= M; ++ i)
        edgesHere[edges[i].c].push_back(i);

    int Q;
    cin >> Q;
    vector <int> v;
    for (int i = 1; i <= Q; ++ i) {
        int cnt;
        cin >> cnt;
        v.resize(cnt);
        for (int j = 0; j < cnt; ++ j)
            cin >> v[j];
        sort(v.begin(), v.end(), [&](const int &a, const int &b) {
            return edges[a].c < edges[b].c;
        });

        int k = 0;
        for (int j = 0; j < cnt; j = k + 1) {
            k = j;
            const int cst = edges[v[j]].c;
            while (k + 1 < cnt && edges[v[k + 1]].c == cst)
                ++ k;
            queriesHere[cst].push_back(make_pair(vector <int>(k - j + 1), i));
            int pos = 0;
            for (int l = j; l <= k; ++ l)
                queriesHere[cst].back().first[pos ++] = v[l];
        }
    }

    for (int i = 1; i <= Q; ++ i)
        queryOk[i] = true;

    for (int cst = 0; cst <= 500000; ++ cst) {
        //Do checks
        for (const auto &it: queriesHere[cst]) {
            hasCycle = false;
            int whichQuery = it.second;
            const vector <int> &e = it.first;

            //Inserting in graph
            for (auto pr: e) {
                const int a = find(edges[pr].a);
                const int b = find(edges[pr].b);
                graph[a].push_back(make_pair(b, pr));
                graph[b].push_back(make_pair(a, pr));
            }

            //Check for no cycles
            for (auto pr: e) {
                const int a = find(edges[pr].a);
                const int b = find(edges[pr].b);
                if (!vis[a])
                    dfs(a, -1);
                if (!vis[b])
                    dfs(b, -1);
            }

            if (hasCycle)
                queryOk[whichQuery] = false;

            //Clearing
            for (auto pr: e) {
                const int a = find(edges[pr].a);
                const int b = find(edges[pr].b);
                graph[a].clear();
                graph[b].clear();
                vis[a] = vis[b] = false;
            }
        }

        //Do unites
        for (auto it: edgesHere[cst]) {
            const Edge &edg = edges[it];
            unite(edg.a, edg.b);
            //cout << "unesc " << edg.a << ' ' << edg.b << endl;
        }
    }

    for (int i = 1; i <= Q; ++ i)
        if (queryOk[i])
            cout << "YES\n";
        else
            cout << "NO\n";
    return 0;
}
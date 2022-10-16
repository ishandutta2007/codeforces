#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

const int NMAX = 3 * 100000 + 5;

set <pair <int, int> > edges;

pair <vector <int>, int> graph[NMAX];

int label[NMAX];
vector <int> freq[NMAX];

set <pair <int, int> > pathEdges;
vector <int> pathGraph[NMAX];

int newLabel[NMAX];
int newLabelCnt;

bool vis[NMAX];
void dfsPath(int node) {
    vis[node] = true;
    newLabel[node] = ++ newLabelCnt;
    for (auto it: pathGraph[node])
        if (!vis[it])
            dfsPath(it);
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= M; ++ i) {
        int a, b;
        cin >> a >> b;
        graph[a].first.push_back(b);
        graph[b].first.push_back(a);

        edges.insert(make_pair(a, b));
        edges.insert(make_pair(b, a));
    }

    for (int i = 1; i <= N; ++ i) {
        graph[i].second = i;
        graph[i].first.push_back(i);
        sort(graph[i].first.begin(), graph[i].first.end());
    }

    sort(graph + 1, graph + N + 1);

    int labels = 0;
    for (int i = 1; i <= N; ++ i) {
        if (i == 1 || graph[i].first != graph[i - 1].first)
            ++ labels;
        label[graph[i].second] = labels;
    }

    for (auto it: edges) {
        int A = label[it.first];
        int B = label[it.second];
        if (A < B) {
            if (!pathEdges.count(make_pair(A, B))) {
                pathEdges.insert(make_pair(A, B));
                pathEdges.insert(make_pair(B, A));
                pathGraph[A].push_back(B);
                pathGraph[B].push_back(A);
            }
        }
    }

    for (int i = 1; i <= labels; ++ i)
        if (pathGraph[i].size() < 2) {
            dfsPath(i);
            break;
        }

    for (int i = 1; i <= N; ++ i) {
        label[i] = newLabel[label[i]];
        freq[label[i]].push_back(i);
    }

    for (int i = 1; i <= labels; ++ i) {
        if (i < labels) {
            for (auto it: freq[i])
                for (auto it2: freq[i + 1])
                    if (!edges.count(make_pair(it, it2))) {
                        cout << "NO\n";
                        return 0;
                    }
                    else
                        -- M;
        }

        for (auto it: freq[i])
            for (auto it2: freq[i])
                if (it < it2) {
                    if (!edges.count(make_pair(it, it2))) {
                        cout << "NO\n";
                        return 0;
                    }
                    else
                        -- M;
                }
    }

    if (M > 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i = 1; i <= N; ++ i)
        cout << label[i] << " \n"[i == N];
    return 0;
}
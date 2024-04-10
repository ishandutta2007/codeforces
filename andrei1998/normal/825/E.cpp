#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100000 + 5;

int N, M;
vector <int> graph[NMAX];
int degree[NMAX];

priority_queue <int> pq;

int ans[NMAX];

int main() {
    cin >> N >> M;

    for (int i = 1; i <= M; ++ i) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
        ++ degree[a];
    }

    for (int i = 1; i <= N; ++ i)
        if (!degree[i])
            pq.push(i);

    int label = N;
    while (!pq.empty()) {
        int node = pq.top();
        ans[node] = label --;
        pq.pop();

        for (auto it: graph[node]) {
            degree[it] --;
            if (degree[it] == 0)
                pq.push(it);
        }
    }


    for (int i = 1; i <= N; ++ i)
        cout << ans[i] << " \n"[i == N];
    return 0;
}
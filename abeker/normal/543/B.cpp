#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 3005;
const int INF = 0x3f3f3f3f;

int N, M;
int s1, t1, l1;
int s2, t2, l2;
vector <int> E[MAXN];
int dist[MAXN][MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    scanf("%d%d%d", &s1, &t1, &l1);
    scanf("%d%d%d", &s2, &t2, &l2);
}

int solve() {
    memset(dist, INF, sizeof dist);
    for (int i = 1; i <= N; i++) {
        queue <int> Q;
        dist[i][i] = 0;
        Q.push(i);
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int j = 0; j < E[x].size(); j++)
                if (dist[i][E[x][j]] == INF) {
                    dist[i][E[x][j]] = dist[i][x] + 1;
                    Q.push(E[x][j]);
                }
        }
    }
    
    int sol = -1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) 
            for (int k = 0; k < 2; k++) {
                int p1 = dist[s1][i] + dist[i][j] + dist[j][t1];
                int p2 = dist[s2][i] + dist[i][j] + dist[j][t2];
                if (p1 <= l1 && p2 <= l2)
                    sol = max(sol, M - p1 - p2 + dist[i][j]);
                swap(s2, t2);
            }
    if (dist[s1][t1] <= l1 && dist[s2][t2] <= l2) 
        sol = max(sol, M - dist[s1][t1] - dist[s2][t2]);
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}
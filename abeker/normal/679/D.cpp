#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long double ld;

const int MAXN = 405;

int N, M;
vector <int> E[MAXN];
int dist[MAXN][MAXN];
vector <int> group[MAXN][MAXN];
ld prob[MAXN], maks[MAXN];
bool bio[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
}

void bfs(int source, int *d) {
    d[source] = 0;
    queue <int> Q;
    Q.push(source);
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int i = 0; i < E[x].size(); i++) {
            int nxt = E[x][i];
            if (d[nxt] != -1) continue;
            d[nxt] = d[x] + 1;
            Q.push(nxt);
        }            
    }
}

ld calc(vector <int> nodes) {
    if (nodes.empty()) return 0;
    for (int i = 1; i <= N; i++)
        prob[i] = 0;
        
    vector <int> imp;
    for (int i = 0; i < nodes.size(); i++)
        for (int j = 0; j < E[nodes[i]].size(); j++) {
            int tmp = E[nodes[i]][j];
            prob[tmp] += (ld)1 / E[nodes[i]].size();
            if (!bio[tmp]) {
                imp.push_back(tmp);
                bio[tmp] = true;
            }
        }
    
    ld res = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < imp.size(); j++)
            maks[dist[i][imp[j]]] = max(maks[dist[i][imp[j]]], prob[imp[j]]);
        ld sum = 0;
        for (int j = 0; j < imp.size(); j++) {
            sum += maks[dist[i][imp[j]]];
            maks[dist[i][imp[j]]] = 0;
        }
        res = max(res, sum);
    }
    
    for (int i = 0; i < imp.size(); i++)
        bio[imp[i]] = false;
    
    return res / N;
}

ld solve() {
    memset(dist, -1, sizeof dist);
    for (int i = 1; i <= N; i++)
        bfs(i, dist[i]);
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            group[i][dist[i][j]].push_back(j);
    
    ld sol = 0;
    for (int i = 1; i <= N; i++) {
        ld curr = 0;
        for (int j = 0; j < N; j++) 
            curr += calc(group[i][j]);
        sol = max(sol, curr);
    }
    
    return sol;
}

int main() {
    load();
    printf("%.12lf\n", (double)solve());
    return 0;
}
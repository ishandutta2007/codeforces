#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 500005;

int N;
vector <int> E[MAXN];
vector <int> curr;

void load() {
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
}

void dfs(int x, int p, int d) {
    bool leaf = true;
    for (int i = 0; i < E[x].size(); i++) {
        if (E[x][i] == p) continue;
        leaf = false;
        dfs(E[x][i], x, d + 1);
    }
    if (leaf) curr.push_back(d);
}

int solve() {
    int sol = 0;
    for (int i = 0; i < E[1].size(); i++) {
        int child = E[1][i];
        curr.clear();
        dfs(child, 1, 1);
        sort(curr.begin(), curr.end());
        for (int j = 1; j < curr.size(); j++)
            if (curr[j] <= curr[j - 1]) curr[j] = curr[j - 1] + 1;
        sol = max(sol, curr.back());
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}
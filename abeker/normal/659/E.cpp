#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100005;

int N, M;
vector <int> E[MAXN];
bool bio[MAXN];

bool dfs(int x, int p) {
    bio[x] = true;
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i];
        if (nxt == p) continue;
        if (bio[nxt] || dfs(nxt, x)) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int x, y;
        scanf("%d%d", &x, &y);
        E[x].push_back(y);
        E[y].push_back(x);
    }
    
    int sol = 0;   
    for (int i = 1; i <= N; i++) 
        if (!bio[i] && !dfs(i, 0)) sol++;
    
    printf("%d\n", sol);
    
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 305;

int N;
int p[MAXN];
char mat[MAXN][MAXN];
bool bio[MAXN];
vector <int> V;

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", p + i); 
    for (int i = 1; i <= N; i++) 
        scanf("%s", mat[i] + 1);
}

void dfs(int x) {
    bio[x] = true;
    V.push_back(x);
    for (int i = 1; i <= N; i++) 
        if (mat[x][i] == '1' && !bio[i]) dfs(i);
}

void set() {
    vector <int> curr;
    for (int i = 0; i < V.size(); i++)  
        curr.push_back(p[V[i]]);
    sort(V.begin(), V.end());
    sort(curr.begin(), curr.end());
    for (int i = 0; i < V.size(); i++) 
        p[V[i]] = curr[i];
}

void solve() {
    for (int i = 1; i <= N; i++) 
        if (!bio[i]) {
            V.clear();
            dfs(i);
            set();
        }
    for (int i = 1; i <= N; i++) 
        printf("%d ", p[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}
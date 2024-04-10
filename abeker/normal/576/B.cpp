#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;

int N;
int p[MAXN];
bool bio[MAXN], was[MAXN];
vector < vector <int> > V[MAXN];
vector < pii > E;

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", p + i);
}

void dfs(int x) {
    vector <int> tmp;
    for (; !bio[x]; x = p[x]) {
        tmp.push_back(x);
        bio[x] = true;
    }
    V[tmp.size()].push_back(tmp);
}

void build(int x) {
    was[x] = true;
    for (int i = 0; i < (int)V[x].size() - 1; i++)
        for (int j = 0; j < x; j++)
            E.push_back(pii(V[x][i][j], V[x][i + 1][j]));
    
    vector <int> last = V[x].back();
    for (int i = 2 * x; i <= N; i += x)
        if (!was[i] && V[i].size()) {
            for (int k = 0; k < i; k++)
                E.push_back(pii(last[k % x], V[i][0][k]));
            build(i);
        }
}

void solve() {
    for (int i = 1; i <= N; i++)
        dfs(i);
    
    int mini = N + 1;
    for (int i = N; i; i--)
        if (V[i].size()) mini = i;
    
    if (mini > 2) {
        puts("NO");
        return;
    }
    
    if (mini == 2)
        E.push_back(pii(V[2][0][0], V[2][0][1]));
        
    build(mini);
    
    if (E.size() != N - 1) {
        puts("NO");
        return;
    }
    
    puts("YES");
    for (int i = 0; i < E.size(); i++)
        printf("%d %d\n", E[i].first, E[i].second);
}

int main() {
    load();
    solve();
    return 0;
}
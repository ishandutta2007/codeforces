#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int Nmax = 6005;

vector<int> G[Nmax];
int Values[Nmax], LIS[Nmax], LIScnt;
int Ans;

void Dfs(const int node, const int father) {
    int pos = lower_bound(LIS, LIS + LIScnt, Values[node]) - LIS;
    int svalue = LIS[pos], flag = (pos == LIScnt);
    if (pos == LIScnt) ++LIScnt;
    LIS[pos] = Values[node];

    Ans = max(Ans, pos + 1);
    for (int p: G[node])
        if (p != father)
            Dfs(p, node);

    LIS[pos] = svalue;
    if (flag) --LIScnt;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i)
        scanf("%d", &Values[i]);

    for (int i = 1; i < N; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for (int i = 1; i <= N; ++i)
        Dfs(i, 0);

    printf("%d\n", Ans);
}
#include <cstdio>
#include <vector>
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

const int N=100005;

vector <PII> g[N];
int a[N];

void dfs(int x, int pred, int xpred, int tip)
{
    int xpredcurrent=xpred;
    if(tip==2)
    {
        a[x]=1;
        a[xpred]=0;
        xpredcurrent=x;
    }
    for(auto i: g[x])
    {
        if(i.x!=pred) dfs(i.x, x, xpredcurrent, i.y);
    }
}

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, i, x, y, tip;
    vector <int> sol;
    scanf("%d", &n);
    for(i=1;i<n;i++)
    {
        scanf("%d%d%d", &x, &y, &tip);
        g[x].push_back(make_pair(y, tip));
        g[y].push_back(make_pair(x, tip));
    }
    dfs(1, 0, 0, 1);
    for(i=1;i<=n;i++) if(a[i]) sol.push_back(i);
    printf("%d\n", sol.size());
    for(auto t: sol) printf("%d ", t);
}
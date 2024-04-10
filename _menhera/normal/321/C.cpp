#include<bits/stdc++.h>
using namespace std;
const int MAXN = 101010;
int N;
int answer[MAXN];

vector<int> conn[MAXN];
bool cented[MAXN];

int size[MAXN];
int cmax[MAXN];

vector<int> gph;
int dfs1(int a, int pa)
{
    if(cented[a]) return 0;
    gph.push_back(a);
    size[a] = 1;
    cmax[a] = 0;
    for(int x: conn[a])
        if(x != pa)
        {
            int csize = dfs1(x, a);
            size[a] += csize;
            cmax[a] = max(csize, cmax[a]);
        }
    return size[a];
}

int find_centroid(int x)
{
    gph.clear();
    int gsize = dfs1(x, -1);
    for(int a: gph) cmax[a] = max(cmax[a], gsize - size[a]);
    int mini = gph[0];
    for(int a: gph) if( cmax[mini] > cmax[a] ) mini = a;
    return mini;
}
void solve(int x, int a)
{
    int cent = find_centroid(x);
    answer[cent] = a;
    cented[cent] = true;
    for(int y: conn[cent])
        if(!cented[y])
            solve(y, a+1);
}
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N-1; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        conn[u].push_back(v);
        conn[v].push_back(u);
    }
    memset(cented, false, sizeof(cented));
    solve(1, 0);
    for(int i=1; i<=N; ++i)
        printf("%c ", answer[i] + 'A');
}
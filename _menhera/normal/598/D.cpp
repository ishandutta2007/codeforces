#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int N, M, K;
char arr[MAXN][MAXN+1];
int col[MAXN][MAXN];
int ans[MAXN*MAXN];

int dfs(int a, int b, int c)
{
    if(col[a][b]) return 0;
    col[a][b] = c;

    int ans = 0;
    for(int d=0; d<4; ++d)
    {
        if(arr[a+dx[d]][b+dy[d]] == '*') ++ans;
        else ans += dfs(a+dx[d], b+dy[d], c);
    }
    return ans;
}
int main()
{
    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<N; ++i) scanf("%s", arr[i]);

    int c = 1;
    while(K--)
    {
        int a, b; scanf("%d%d", &a, &b); --a; --b;
        if(!col[a][b])
        {
            ans[c] = dfs(a, b, c);
            ++c;
        }
        printf("%d\n", ans[col[a][b]]);
    }
}
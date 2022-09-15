#include<bits/stdc++.h>
using namespace std;
int N, M;
char arr[303][303];
char str[404];
int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; ++i)
        scanf("%s", arr[i]);
    scanf("%s", str);
    int sx, sy;
    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j)
            if(arr[i][j] == 'S')
                tie(sx, sy) = tie(i, j);
    int x[4] = {0, 1, 2, 3};
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int ans = 0;
    do
    {
        int xx = sx;
        int yy = sy;
        int i;
        for(i=0; str[i]; ++i)
        {
            int ddx = dx[x[str[i] - '0']];
            int ddy = dy[x[str[i] - '0']];
            xx += ddx;
            yy += ddy;
            if(xx<0 || yy <0 || xx>=N || yy>=M) break;
            if(arr[xx][yy] == '#') break;
            if(arr[xx][yy] == 'E')
            {
                ++ans;
                break;
            }
        }
        
    }while(next_permutation(x, x+4));
    printf("%d\n", ans);
}
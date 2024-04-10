#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N=100005;

char a[N];
int b[N][3];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, m, i, x, y;
    int c[3];
    a[0]='!';
    fgets(a+1, N ,stdin);
    n=strlen(a)-2;
    for(i=1;i<=n;i++)
    {
        b[i][0]=b[i-1][0];
        b[i][1]=b[i-1][1];
        b[i][2]=b[i-1][2];
        if(a[i]=='x') b[i][0]++;
        else if(a[i]=='y') b[i][1]++;
        else b[i][2]++;
    }
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d%d", &x, &y);
        if(y-x<2) printf("YES\n");
        else
        {
            c[0]=b[y][0]-b[x-1][0];
            c[1]=b[y][1]-b[x-1][1];
            c[2]=b[y][2]-b[x-1][2];
            if(!c[0]||!c[1]||!c[2])
            {
                printf("NO\n");
                continue;
            }
            sort(c, c+3);
            //printf("%d %d %d\n", c[0], c[1], c[2]);
            if(c[0]==c[1]&&c[2]==c[1]+1)
            {
                printf("YES\n");
                continue;
            }
            if(c[1]==c[2]&&c[1]==c[0]+1)
            {
                printf("YES\n");
                continue;
            }
            if(c[0]==c[1]&&c[1]==c[2])
            {
                printf("YES\n");
                continue;
            }
            printf("NO\n");
        }
    }
}
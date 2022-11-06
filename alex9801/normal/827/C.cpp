#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

char arr[100010];
char que[20];

int bit[220][100010];
int enc[11][10][4];

int cha(char c)
{
    if(c == 'A')
        return 0;
    if(c == 'T')
        return 1;
    if(c == 'C')
        return 2;
    return 3;
}

int sum(int bit[], int x)
{
    x++;
    int r = 0;
    while(x)
    {
        r += bit[x];
        x -= x&-x;
    }
    return r;
}

void upd(int bit[], int n, int x, int v)
{
    x++;
    while(x <= n)
    {
        bit[x] += v;
        x += x&-x;
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    char c;
    int n, m, q, t, l, r, x, e, i, j, k;
    scanf("%s%d", arr, &q);

    n = strlen(arr);

    t = 0;
    for(i = 1; i<=10; i++)
        for(j = 0; j<i; j++)
            for(k = 0; k<4; k++)
                enc[i][j][k] = t++;
    
    for(i = 0; i<n; i++)
    {
        t = cha(arr[i]);
        for(j = 1; j<=10; j++)
            upd(bit[enc[j][i%j][t]], (n-1-i%j)/j+1, (i-i%j)/j, 1);
    }

    for(i = 0; i<q; i++)
    {
        scanf("%d", &t);
        if(t == 1)
        {
            scanf("%d %c", &x, &c);
            x--;

            t = cha(arr[x]);
            for(j = 1; j<=10; j++)
                upd(bit[enc[j][x%j][t]], (n-1-x%j)/j+1, (x-x%j)/j, -1);

            arr[x] = c;

            t = cha(arr[x]);
            for(j = 1; j<=10; j++)
                upd(bit[enc[j][x%j][t]], (n-1-x%j)/j+1, (x-x%j)/j, 1);
        }
        else
        {
            scanf("%d%d%s", &l, &r, que);
            l--;
            r--;

            m = strlen(que);
            
            e = 0;
            for(x = 0; x<m; x++)
            {
                if(l+x > r)
                    break;

                t = cha(que[x]);
                if(l+x-m >= 0)
                    e += sum(bit[enc[m][(x+l)%m][t]], (r-(x+l)%m)/m) - sum(bit[enc[m][(x+l)%m][t]], (l-1-(x+l)%m)/m);
                else
                    e += sum(bit[enc[m][(x+l)%m][t]], (r-(x+l)%m)/m);
            }
            printf("%d\n", e);
        }
    }
    return 0;
}
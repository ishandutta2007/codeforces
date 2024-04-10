#include <bits/stdc++.h>
using namespace std;

char arr[100010];
bool chk[10];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i, j;
    scanf("%d%s", &n, arr);

    for(i = 0; i < n; i++)
    {
        if(arr[i] == 'L')
        {
            for(j = 0; j < 10; j++)
            {
                if(!chk[j])
                {
                    chk[j] = 1;
                    break;
                }
            }
        }
        else if(arr[i] == 'R')
        {
            for(j = 9; j >= 0; j--)
            {
                if(!chk[j])
                {
                    chk[j] = 1;
                    break;
                }
            }
        }
        else
        {
            chk[arr[i] - '0'] = 0;
        }
    }

    for(i = 0; i < 10; i++)
        printf("%d", (int)chk[i]);
    puts("");

    return 0;
}
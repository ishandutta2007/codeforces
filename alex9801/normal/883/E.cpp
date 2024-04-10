#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>

using namespace std;

char arr[60];
char mem[1010][60];
bool chk[26];
bool val[1010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    bool u, v;
    int n, m, r, i, j;
    scanf("%d%s%d", &n, arr, &m);
    for(i = 0; i < m; i++)
        scanf("%s", mem[i]);

    for(i = 0; i < n; i++)
        if(arr[i] != '*')
            chk[arr[i] - 'a'] = 1;

    for(i = 0; i < m; i++)
    {
        val[i] = 1;
        for(j = 0; j < n; j++)
        {
            if(arr[j] != '*')
            {
                if(arr[j] != mem[i][j])
                {
                    val[i] = 0;
                    break;
                }
            }
            else
            {
                if(chk[mem[i][j] - 'a'])
                {
                    val[i] = 0;
                    break;
                }
            }
        }
    }

    r = 0;
    for(char c = 'a'; c <= 'z'; c++)
    {
        if(chk[c - 'a'])
            continue;

        u = 1;
        for(i = 0; i < m; i++)
        {
            if(!val[i])
                continue;

            v = 1;
            for(j = 0; j < n; j++)
            {
                if(mem[i][j] == c)
                {
                    if(arr[j] == '*')
                        v = 0;
                    else
                    {
                        u = 0;
                        break;
                    }
                }
            }
            if(v)
                u = 0;

            if(!u)
                break;
        }

        if(u)
            r++;
    }

    printf("%d", r);
    return 0;
}
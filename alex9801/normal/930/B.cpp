#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
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

char arr[5010];
int chk[26][5010][26];
double prob[26];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i, j, k;
    scanf("%s", arr);
    
    n = strlen(arr);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
                continue;

            chk[arr[i] - 'a'][(i - j + n) % n][arr[j] - 'a']++;
        }
    }

    for(i = 0; i < 26; i++)
    {
        for(j = 1; j < n; j++)
        {
            int p, q;
            p = q = 0;
            for(k = 0; k < 26; k++)
            {
                q += chk[i][j][k];
                if(chk[i][j][k] == 1)
                    p++;
            }

            prob[i] = max(prob[i], 1.0 * p / q);
        }
    }

    double res = 0;
    for(i = 0; i < n; i++)
        res += 1.0 / n * prob[arr[i] - 'a'];
    
    printf("%.10lf", res);

    return 0;
}
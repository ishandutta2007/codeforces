#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxDim 555

int n, i, j;
int cnt;

int ans[maxDim][maxDim];

int main()
{
    scanf("%d", &cnt);

    n = 1;
    ans[1][1] = 0;

    while (cnt > 0) {
        cnt--;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                ans[i + n][j] = ans[i][j + n] = ans[i][j];
                ans[i + n][j + n] = ans[i][j] ^ 1;
            }
        }

        n <<= 1;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%c", (ans[i][j] ? '+' : '*'));
        printf("\n");
    }

    //! checker...

    return 0;

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            int same = 0;
            int diff = 0;

            for (int t = 1; t <= n; t++)
                if (ans[i][t] == ans[j][t])
                    same++;
                else
                    diff++;

            if (same != diff)
                return 2016;
        }
    }


    return 0;
}
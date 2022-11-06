#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 55

int n, m, i, j, k, l;
int a[maxN][maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j] != 1) {
                bool good = false;

                for (k = 1; k <= n; k++)
                    for (l = 1; l <= n; l++)
                        if (a[i][j] == a[i][k] + a[l][j])
                            good = true;

                if (good == false) {
                    printf("No");
                    return 0;
                    }
            }


    printf("Yes");

    return 0;
}
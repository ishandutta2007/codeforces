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

const int maxN = 111;

int n, k, i, j, p, maxi;
char s[maxN][maxN];
int ans[maxN][maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n", &n, &k);
    for (i = 1; i <= n; i++) scanf("%s\n", s[i] + 1);

    for (i = 1; i + k - 1 <= n; i++) {
        for (j = 1; j <= n; j++) {
            for (p = 0; p < k; p++)
                if (s[i + p][j] == '#')
                    break;

            if (p == k)
                for (p = 0; p < k; p++)
                    ans[i + p][j]++;
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j + k - 1 <= n; j++) {
            for (p = 0; p < k; p++)
                if (s[i][j + p] == '#')
                    break;

            if (p == k)
                for (p = 0; p < k; p++)
                    ans[i][j + p]++;
        }
    }

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            maxi = max(maxi, ans[i][j]);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (ans[i][j] == maxi) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }


    return 0;
}
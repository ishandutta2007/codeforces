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

#define maxN 1024

int n, m, i, j;
char s[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n", &n, &m);
    for (i = 1; i <= n; i++) {
        gets(s + 1);
        for (j = 1; j <= 2 * m; j += 2)
            if (s[j] != 'W' && s[j] != 'B' && s[j] != 'G') {
                printf("#Color");
                return 0;
            }
    }


    printf("#Black&White");
    return 0;
}
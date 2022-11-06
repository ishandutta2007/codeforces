#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 111

int n, m, i, k, j, x;
bool on[maxN];
int cnt;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d", &k);
        for (j = 1; j <= k; j++) {
            scanf("%d", &x);
            if (on[x] == false)
                cnt++;
            on[x] = true;
        }
    }

    if (cnt == m)
        printf("YES");
    else
        printf("NO");


    return 0;
}
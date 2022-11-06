#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

int n, t, i;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &t);

    if (t < 10) {
        for (i = 1; i <= n; i++) printf("%d", t);
    } else {
        if (n == 1) {
            printf("-1");
            return 0;
        }

        printf("1");
        for (i = 1; i < n; i++) printf("0");
    }




    return 0;
}
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

int n, k, x, dy, y;

void p(int x, int y) {
    printf("%d %d\n", x, y);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);

    if (k == 3) {
        if (n == 3) {
            printf("0 0\n0 1\n1 0\n");
            return 0;
        }

        if (n == 4) {
            printf("0 0\n0 100\n100 0\n1 1\n");
            return 0;
        }

        printf("-1");
        return 0;
    }

    p(0, 0);
    n--; k--;

    dy = 300;
    x = 0; y = 0;
    while (k > 0) {
        x--;
        dy--;

        p(x, y + dy);
        k--; n--;
        if (k == 0) break;

        p(x, -y - dy);
        k--; n--;

        y += dy;
    }

    ////

    dy = 300;
    x = 100; y = 0;
    while (n > 0) {
        x++;
        dy--;

        p(x, y + dy);
        n--;
        if (n == 0) break;

        p(x, -y - dy);
        n--;

        y += dy;
    }




    return 0;
}
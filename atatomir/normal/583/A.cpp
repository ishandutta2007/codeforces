#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 55

int n, i, x, y;
bool done_l[maxN], done_c[maxN];
bool need;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    n *= n;

    for (i = 1; i <= n; i++) {
        scanf("%d%d", &x, &y);

        need = true;
        if (done_l[x] == true) need = false;
        if (done_c[y] == true) need = false;

        if (need) {
            done_l[x] = done_c[y] = true;
            printf("%d ", i);
        }
    }


    return 0;
}
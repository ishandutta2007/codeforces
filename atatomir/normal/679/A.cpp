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

int n, i, j;
bool ciur[maxN];
vector<int> pr;

char ans[10];
int cnt, last;

int main()
{
    n = 50;
    for (i = 2; i <= n; i++) {
        if (ciur[i]) continue;

        pr.pb(i);
        for (j = i * i; j <= n; j += i) ciur[j] = true;
    }

    for (auto e : pr) {
        printf("%d\n", e);
        fflush(stdout);

        memset(ans, 0, sizeof(ans));
        scanf("%s", ans + 1);

        if (ans[1] == 'y') {
            last = e;
            if (++cnt == 2) {
                printf("composite\n");
                fflush(stdout);
                return 0;
            }
        }
    }

    if (cnt == 1 && last * last <= 100) {
        printf("%d\n", last * last);
        fflush(stdout);

        memset(ans, 0, sizeof(ans));
        scanf("%s", ans + 1);

        if (ans[1] == 'y') {
            printf("composite\n");
            fflush(stdout);
            return 0;
        }
    }

    printf("prime\n");
    fflush(stdout);

    return 0;
}
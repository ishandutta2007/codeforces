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

#define maxX 1033

int n, k, x, i, j, ss, dd, mv, p;
int tp[2][maxX];

bool fr;



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &k, &x);

    ss = 0; dd = 1;
    for (i = 1; i <= n; i++) {
        scanf("%d", &p);
        tp[ss][p]++;
    }

    for (i = 1; i <= k; i++) {
        memset(tp[dd], 0, sizeof(tp[dd]));
        fr = true;

        for (j = 0; j <= 1024; j++) {
            mv = (fr ? (tp[ss][j] + 1) >> 1 : tp[ss][j] >> 1);
            tp[dd][j ^ x] += mv;
            tp[dd][j] += tp[ss][j] - mv;

            fr ^= (tp[ss][j] & 1);
        }

        swap(ss, dd);
    }

    int mini = 1024;
    int maxi = 0;

    for (i = 0; i <= 1024; i++) {
        if (tp[ss][i]) {
            maxi = max(maxi, i);
            mini = min(mini, i);
        }
    }

    printf("%d %d", maxi, mini);



    return 0;
}
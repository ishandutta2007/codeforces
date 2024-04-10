#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 100011

int n,i;
int bids[maxN];
int all_cmmdc;

int cmmdc(int a, int b) {
    if (a < b) swap(a,b);

    while (b) {
        a %= b;
        swap(a,b);
    }

    return a;
}

int main()
{
    scanf("%d",&n);
    for (i = 1; i <= n; i++) scanf("%d",&bids[i]);
    all_cmmdc = bids[1];

    for (i = 2; i <= n; i++) all_cmmdc = cmmdc(all_cmmdc, bids[i]);
    for (i = 1; i <= n; i++) {
        bids[i] /= all_cmmdc;

        while ((bids[i] & 1) == 0) bids[i] >>= 1;
        while (bids[i] % 3 == 0) bids[i] /= 3;

        if (bids[i] != 1) {
            printf("No");
            return 0;
        }
    }

    printf("Yes");
    return 0;
}
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

#define maxN 100011

int n, i;
ll V[maxN], T[maxN], sum[maxN];

ll full[maxN];
ll bonus[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%lld", &V[i]);
    for (i = 1; i <= n; i++) scanf("%lld", &T[i]), sum[i] = T[i] + sum[i - 1];

    for (i = 1; i <= n; i++) {
        int p = upper_bound(sum + i, sum + n + 1, V[i] + sum[i - 1]) - sum;
        full[i]++;
        full[p]--;
        bonus[p] += V[i] - (sum[p - 1] - sum[i - 1]);
    }

    for (i = 1; i <= n; i++) {
        full[i] += full[i - 1];
        printf("%lld ", full[i] * T[i] + bonus[i]);
    }


    return 0;
}
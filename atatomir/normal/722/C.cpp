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
int v[maxN];
int ord[maxN];

bool valid[maxN];
int dad[maxN];
ll sum[maxN];
ll ans[maxN];


int Find(int x) {
    if (dad[x] == x) return x;
    dad[x] = Find(dad[x]);
    return dad[x];
}

bool Merge(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y)
        return false;

    dad[x] = y;
    sum[y] += sum[x];

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &v[i]);
    for (i = 1; i <= n; i++) scanf("%d", &ord[i]);
    for (i = 1; i <= n; i++) {
        dad[i] = i;
        sum[i] = v[i];
    }

    for (i = n; i > 0; i--) {
        int pos = ord[i];

        valid[pos] = true;
        if (valid[pos - 1]) Merge(pos, pos - 1);
        if (valid[pos + 1]) Merge(pos, pos + 1);

        ans[i] = max(ans[i + 1], sum[Find(pos)]);
    }

    for (i = 2; i <= n + 1; i++)
        printf("%lld\n", ans[i]);


    return 0;
}
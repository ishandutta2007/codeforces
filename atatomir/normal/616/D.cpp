#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long

#define maxN 1000011

int n, i, k, limit;
int v[maxN];
int aib[maxN];
int last[maxN];

int best;
int l, r;

int zrs(int x) {
    return (x & (x - 1)) ^ x;
}

void add(int pos, int v) {
    while (pos <= n) {
        aib[pos] += v;
        pos += zrs(pos);
    }
}

int sum(int pos) {
    int ans = 0;

    while (pos > 0) {
        ans += aib[pos];
        pos -= zrs(pos);
    }

    return ans;
}

int main()
{
    //freopen("test.in", "r", stdin);

    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    for (i = 1; i <= n; i++) {
        int pos = last[ v[i] ];

        if (pos)
            add(pos, -1);
        add(i, +1);

        last[ v[i] ] = i;

        int sum_now = sum(i);
        while (sum_now - sum(limit) > k) limit++;

        if (best < i - limit) {
            best = i - limit;
            l = limit + 1;
            r = i;
        }
    }

    printf("%d %d", l, r);

    return 0;
}
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

#define maxN 2000011

int n, i, x;
int cnt[maxN];
int ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }

    for (i = 0; i <= 2000000; i++) {
        ans += cnt[i] & 1;
        cnt[i + 1] += cnt[i] >> 1;
    }

    printf("%d", ans);


    return 0;
}
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

#define maxN 555

int n, k, i;
int a[maxN];
int ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);
    a[0] = a[n + 1] = k;
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (i = 2; i <= n; i++) {
        int sum = a[i - 1] + a[i];
        if (sum < k) {
            ans += k - sum;
            a[i] += k - sum;
        }
    }

    printf("%d\n", ans);
    for (i = 1; i <= n; i++) printf("%d ", a[i]);


    return 0;
}
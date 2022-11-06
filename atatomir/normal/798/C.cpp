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
int a[maxN], d, ans;

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);

    d = a[1];
    for (i = 2; i <= n; i++) d = gcd(d, a[i]);

    if (d > 1) {
        printf("YES\n0");
        return 0;
    }

    for (i = 1; i < n; i++) {
        if (a[i] % 2 == 1 && a[i + 1] % 2 == 1) {
            ans++;
            a[i] -= 1;
            a[i + 1] -= 1;
        }
    }

    for (i = 1; i <= n; i++)
        if (a[i] % 2 == 1)
            ans += 2;

    printf("YES\n%d", ans);

    return 0;
}
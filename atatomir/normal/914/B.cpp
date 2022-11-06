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

int n, i, j;
int a[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);

    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i = j) {
        for (j = i; j <= n; j++)
            if (a[i] != a[j])
                break;

        if ((j - i) % 2 == 1) {
            printf("Conan");
            return 0;
        }
    }

    printf("Agasa");


    return 0;
}
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
bool pr[maxN];

void solve() {
    ll i, j;

    n++;

    if (n <= 3) {
        printf("1\n");
        for (i = 2; i <= n; i++)
            printf("1 ");
        exit(0);
    }

    printf("2\n");
    for (i = 2; i <= n; i++) {
        if (pr[i]) {
            printf("2 ");
            continue;
        }

        printf("1 ");
        for (j = i * i; j <= n; j += i)
            pr[j] = true;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    solve();


    return 0;
}
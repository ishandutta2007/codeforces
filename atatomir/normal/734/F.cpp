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

#define maxN 200011

const int bits = 30;

int n, i;
ll b[maxN], c[maxN], a[maxN];
ll S, aux;

ll cnt[bits + 13];


void no_sol() {
    printf("-1");
    exit(0);
}

bool check() {
    int i, j;
    ll bb, cc, poww;

    for (i = 1; i <= n; i++)
        for (j = 0; j <= bits; j++)
            cnt[j] += ((a[i] >> j) & 1);

    for (i = 1; i <= n; i++) {
        bb = cc = 0;
        poww = 1;

        for (j = 0; j <= bits; j++) {
            if ((a[i] >> j) & 1) { // this bit is 1
                bb += cnt[j] * poww;
                cc += n * poww;
            } else { // this bit is 0
                cc += cnt[j] * poww;
            }

            poww <<= 1;
        }

        if (bb != b[i]) return false;
        if (cc != c[i]) return false;
    }

    return true;
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%lld", &b[i]), S += b[i];
    for (i = 1; i <= n; i++) scanf("%lld", &c[i]), S += c[i];

    if (S % (2 * n) != 0) no_sol();
    S /= 2 * n;

    for (i = 1; i <= n; i++) {
        aux = b[i] + c[i] - S;
        if (aux < 0) no_sol();
        if (aux % n != 0) no_sol();
        a[i] = aux / n;
    }

    if (!check())
        no_sol();


    for (i = 1; i <= n; i++)
        printf("%lld ", a[i]);


    return 0;
}
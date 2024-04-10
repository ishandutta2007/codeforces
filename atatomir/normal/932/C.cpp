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

#define maxN 1000011

int n, A, B, i, j, m;

void make_cyc(int sz) {
    int i;

    if (sz == 1) {
        m++;
        printf("%d ", m);
    } else {
        for (i = 2; i <= sz; i++)
            printf("%d ", m + i);
        printf("%d ", m + 1);
        m += sz;
    }
}

void gen(int cnt1, int cnt2) {
    for (int i = 1; i <= cnt1; i++) make_cyc(A);
    for (int i = 1; i <= cnt2; i++) make_cyc(B);
    if (m != n) cerr << "Err";
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &A, &B);

    for (i = 0; i * A <= n; i++) {
        j = n - i * A;
        if (j % B != 0) continue;
        gen(i, j / B);
        return 0;
    }

    printf("-1");

    return 0;
}
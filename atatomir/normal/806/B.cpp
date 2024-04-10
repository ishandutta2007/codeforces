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

#define maxN 122

int n, i, j;
int tmp[maxN][11];
int cnt[11], aux[11];
int value[11];

bool solve(int sz) {
    int i;

    memcpy(aux, cnt, sizeof(aux));
    for (i = 1; i <= 5; i++) {
        if (tmp[1][i] != -1 && tmp[2][i] != -1 && tmp[1][i] > tmp[2][i]) {
            aux[i] += sz;
        }
    }

    int total = n + sz;
    for (i = 1; i <= 5; i++) {
        value[i] = 3000;

        if (aux[i] > total / 32) value[i] = 2500;
        if (aux[i] > total / 16) value[i] = 2000;
        if (aux[i] > total / 8) value[i] = 1500;
        if (aux[i] > total / 4) value[i] = 1000;
        if (aux[i] > total / 2) value[i] = 500;
    }

    int points = 0;
    for (i = 1; i <= 5; i++) {
        if (tmp[1][i] != -1) {
            points += value[i] - (value[i] / 250) * tmp[1][i];
        }

        if (tmp[2][i] != -1) {
            points -= value[i] - (value[i] / 250) * tmp[2][i];
        }
    }

    return points > 0;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= 5; j++) {
            scanf("%d", &tmp[i][j]);
            if (tmp[i][j] != -1) cnt[j]++;
        }
    }

    for (i = 0; solve(i) == false && i <= 50 * n; i++);
    if (i > 50 * n) {
        printf("-1");
        return 0;
    }

    printf("%d", i);


    return 0;
}
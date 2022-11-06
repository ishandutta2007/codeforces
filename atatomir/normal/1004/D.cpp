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

const int maxVal = 1000011;

int n, i, x, comp;
int cnt[maxVal], aux[maxVal], maxi;
int last[maxVal];

void give(int x) {
    printf("%d", x);
    exit(0);
}

void brute(int n, int m, int x, int y) {
    int i, j, dif;
    static int act = 0;

    act++;

    //cerr << n << ' ' << m << ' ' << x << ' ' << y << '\n';

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            dif = abs(x - i) + abs(y - j);
            if (last[dif] != act) {
                last[dif] = act;
                aux[dif] = 0;
            }
            if (++aux[dif] > cnt[dif]) return;
        }
    }

    printf("%d %d\n%d %d", n, m, x, y);
    exit(0);
}

void check(int n, int m) {
    int i, j, x, y;
    int ln, co;

    ln = n - comp + 1;
    co = m - comp + 1;

    for (x = 1; x <= n; x++) {
        y = maxi - x + 2;

        if (y <= 0 || y > m) continue;
        if (x != ln && y != co) continue;

        brute(n, m, x, y);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        cnt[x]++;
        maxi = max(maxi, x);
    } 

    if (cnt[0] != 1) give(-1);

    for (i = 1; i <= maxi; i++)
        if (cnt[i] > 4 * i)
            give(-1);

    for (comp = 1; cnt[comp] == 4 * comp; comp++);

    for (i = 1; i * i <= n; i++) {
        if (n % i) continue;
        check(i, n / i);
    }

    give(-1);

    return 0;
}
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

#define maxN 1024

int n, i, pos0, pos1, aux1, aux2;
char s[maxN];

int ask1(int cnt) {
    int i;

    for (i = 1; i <= n; i++) s[i] = '0';
    for (i = 1; i <= cnt; i++) s[i] = '1';

    printf("? %s\n", s + 1);
    fflush(stdout);
    scanf("%d", &i);
    return n - i;
}

int main()
{
    scanf("%d", &n);

    aux1 = ask1(0);
    aux2 = ask1(1);
    if (aux2 < aux1) {
        pos0 = 1;
    } else {
        pos1 = 1;
    }

    if (pos0 == 0) {
        for (int step = 1 << 10; step > 0; step >>= 1)
            if (pos0 + step <= n)
                if (ask1(pos0 + step) == aux1 + pos0 + step)
                    pos0 += step;
        pos0++;
    } else {
        for (int step = 1 << 10; step > 0; step >>= 1)
            if (pos1 + step <= n)
                if (ask1(pos1 + step) == aux1 - pos1 - step)
                    pos1 += step;
        pos1++;
    }

    printf("! %d %d\n", pos0, pos1);
    fflush(stdout);


    return 0;
}
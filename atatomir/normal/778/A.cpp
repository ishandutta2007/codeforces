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

int n, m, i;
char s[maxN], pat[maxN];
int P[maxN], wh[maxN];

bool check(int limit) {
    int i, pos;

    pat[m + 1] = '@';

    pos = 1;
    for (i = 1; i <= n; i++) {
        if (wh[i] <= limit) continue;

        if (s[i] == pat[pos])
            pos++;
    }

    return (pos == m + 1);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s\n%s\n", s + 1, pat + 1);
    n = strlen(s + 1);
    m = strlen(pat + 1);
    for (i = 1; i <= n; i++) scanf("%d", &P[i]), wh[ P[i] ] = i;


    int ans = 0;
    for (int step = 1 << 20; step > 0; step >>= 1)
        if (ans + step <= n)
            if (check(ans + step))
                ans += step;

    printf("%d", ans);


    return 0;
}
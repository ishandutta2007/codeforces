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

#define maxN 111
#define maxLen 30

int dim, n, i, ans, act;
int v[maxN];
int sg[maxN];
char s[maxN * maxLen];

int read_nr() {
    int ans = 0;

    for (int i = 1; i <= dim; i++)
        if ('0' <= s[i] && s[i] <= '9')
            ans = ans * 10 + s[i] - '0';

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    gets(s + 1);
    dim = strlen(s + 1);

    sg[1] = +1;
    for (i = 1; i <= dim; i++) {
        if (s[i] == '?')
            n++;

        if (s[i] == '+')
            sg[n + 1] = +1;

        if (s[i] == '-')
            sg[n + 1] = -1;
    }

    ans = read_nr();
    for (i = 1; i <= n; i++) {
        if (sg[i] < 0) {
            v[i] = 1;
            act--;
        } else {
            v[i] = 1;
            act++;
        }
    }

    if (act < ans) {
        for (i = 1; i <= n; i++) {
            if (sg[i] < 0) continue;

            int addon = min(ans - act, ans - v[i]);
            v[i] += addon;
            act += addon;
        }
    } else {
        for (i = 1; i <= n; i++) {
            if (sg[i] > 0) continue;

            int addon = min(act - ans, ans - v[i]);
            v[i] += addon;
            act -= addon;
        }
    }

    if (act != ans) {
        printf("Impossible");
        return 0;
    }

    printf("Possible\n");
    for (i = 1; i <= n; i++) {
        if (i > 1)
            printf("%c ", (sg[i] < 0 ? '-' : '+'));
        printf("%d ", v[i]);
    }

    printf("= %d\n", ans);

    return 0;
}
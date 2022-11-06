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

#define maxN 55

int n, m, i, j, limit;
char s[maxN][maxN];
ll indist[1 << 20];
double ch[maxN];
double ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n", &n);
    for (i = 1; i <= n; i++)
        scanf("%s\n", s[i]);

    m = strlen(s[1]);
    limit = 1 << m;

    ch[0] = 1;
    for (i = 1; i <= m; i++) {
        ch[i] = 1;

        for (j = 1; j <= i; j++)
            ch[i] *= 1.00 * (i - j + 1) / (m - j + 1);
    }

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            ll mask = 0;

            for (int k = 0; k < m; k++)
                if (s[i][k] == s[j][k])
                    mask |= 1 << k;

            indist[mask] |= 1LL << i;
            indist[mask] |= 1LL << j;
        }
    }

    for (int conf = limit - 1; conf > 0; conf--) {
        for (i = 0; i < m; i++)
            if ( (conf >> i) & 1 )
                indist[conf ^ (1 << i)] |= indist[conf];
    }

    for (int conf = 0; conf < limit; conf++) {
        int cnt = 0;

        while (indist[conf] > 0) {
            if (indist[conf] & 1) cnt++;
            indist[conf] >>= 1;
        }

        ans += 1.00 * cnt * ch[ __builtin_popcount(conf) ];
    }

    ans /= n;
    printf("%.15lf", ans);


    return 0;
}
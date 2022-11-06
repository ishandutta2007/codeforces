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

int n, m, k, i, j, cnt;
char s[maxN];
int ln[maxN][maxN], co[maxN][maxN], dif, tot;
int ans[maxN][maxN];

void check_one() {
    int i, j;
    int good = tot - dif;

    if (4 * good >= 3 * tot) {
        printf("YES\n");
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++)
                printf("1 ");
            printf("\n");
        }
    } else {
        printf("NO\n");
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d\n", &n, &m, &k);
    for (i = 1; i <= n; i++) {
        scanf("%s\n", s + 1);
        for (j = 1; j < m; j++) ln[i][j] = (s[j] == 'N' ? 1 : 0), dif += ln[i][j], tot++;
        if (i == n) break;
        scanf("%s\n", s + 1);
        for (j = 1; j <= m; j++) co[i][j] = (s[j] == 'N' ? 1 : 0), dif += co[i][j], tot++;
    }

    if (k == 1) {
        check_one();
        return 0;
    }

    if ((n - 1) * m <= (m - 1) * n) {
        ans[1][1] = 0;
        for (i = 2; i <= m; i++) ans[1][i] = ans[1][i - 1] ^ ln[1][i - 1];
        for (i = 2; i <= n; i++) {
            ans[i][1] = 0;
            for (j = 2; j <= m; j++) ans[i][j] = ans[i][j - 1] ^ ln[i][j - 1];

            cnt = 0;
            for (j = 1; j <= m; j++)
                if (co[i - 1][j] != (ans[i][j] ^ ans[i - 1][j]))
                    cnt++;

            if (m - cnt < cnt)
                for (j = 1; j <= m; j++)
                    ans[i][j] ^= 1;
        }
    } else {
        ans[1][1] = 0;
        for (i = 2; i <= n; i++) ans[i][1] = ans[i - 1][1] ^ co[i - 1][1];
        for (j = 2; j <= m; j++) {
            ans[1][j] = 0;
            for (i = 2; i <= n; i++) ans[i][j] = ans[i - 1][j] ^ co[i - 1][j];

            cnt = 0;
            for (i = 1; i <= n; i++)
                if (ln[i][j - 1] != (ans[i][j - 1] ^ ans[i][j]))
                    cnt++;

            if (n - cnt < cnt)
                for (i = 1; i <= n; i++)
                    ans[i][j] ^= 1;
        }
    }

    printf("YES\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++)
            printf("%d ", ans[i][j] + 1);
        printf("\n");
    }


    return 0;
}
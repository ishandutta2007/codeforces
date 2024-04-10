#include <bits/stdc++.h>

using namespace std;

const int MX = 100;

char s[MX][MX + 1], p[MX + 1];
int a[MX];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf(" %s", s[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d", a + i);
        a[i]--;
    }

    int k = strlen(s[a[0]]);
    for (int i = 1; i < m; i++)
        if (strlen(s[a[i]]) != k) {
            printf("No\n");

            return 0;
        }

    for (int i = 0; i <= k; i++) p[i] = s[a[0]][i];
    for (int i = 1; i < m; i++)
        for (int j = 0; j < k; j++)
            if (p[j] != s[a[i]][j])
                p[j] = '?';

    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < m; j++) ok = ok && (a[j] != i);

        if (ok == false || strlen(s[i]) != k) continue;

        for (int j = 0; j < k; j++) ok = ok && (p[j] == '?' || p[j] == s[i][j]);

        if (ok) {
            printf("No\n");

            return 0;
        }
    }

    printf("Yes\n%s\n", p);

    return 0;
}
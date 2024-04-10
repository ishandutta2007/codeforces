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

int n, i, j;
char s[maxN][maxN];
bool data[maxN][maxN];
int xx1, yy1, xx2, yy2;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n", &n);
    for (i = 1; i <= n; i++) scanf("%s\n", s[i] + 1);

    xx1 = yy1 = n + 3;
    xx2 = yy2 = -1;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (s[i][j] == '0') continue;
            xx1 = min(xx1, i);
            yy1 = min(yy1, j);
            xx2 = max(xx2, i);
            yy2 = max(yy2, j);
        }
    }

    if (xx2 == -1) {
        printf("No");
        return 0;
    }

    for (i = xx1; i < xx2; i++)
        for (j = yy1; j < yy2; j++)
            data[i][j]++;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (data[i - 1][j - 1]) s[i][j]--;
            if (data[i - 1][j]) s[i][j]--;
            if (data[i][j - 1]) s[i][j]--;
            if (data[i][j]) s[i][j]--;

            if (s[i][j] != '0') {
                printf("No");
                return 0;
            }
        }
    }

    printf("Yes");


    return 0;
}
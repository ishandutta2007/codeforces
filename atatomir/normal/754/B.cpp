#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 11

int i, j;
char s[maxN][maxN];

bool check() {
    int i, j;

    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 2; j++) {
            if (s[i][j] == 'x' && s[i][j + 1] == 'x' && s[i][j + 2] == 'x') return true;
        }
    }

    for (i = 1; i <= 2; i++) {
        for (j = 1; j <= 4; j++) {
            if (s[i][j] == 'x' && s[i + 1][j] == 'x' && s[i + 2][j] == 'x') return true;
        }
    }

    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 4; j++) {
            if (i + 2 > 4 || j + 2 > 4) continue;

            if (s[i][j] == 'x' && s[i + 1][j + 1] == 'x' && s[i + 2][j + 2] == 'x') return true;
        }
    }

    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 4; j++) {
            if (i - 2 <= 0 || j + 2 > 4) continue;

            if (s[i][j] == 'x' && s[i - 1][j + 1] == 'x' && s[i - 2][j + 2] == 'x') return true;
        }
    }


    return false;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s\n%s\n%s\n%s", s[1] + 1, s[2] + 1, s[3] + 1, s[4] + 1);

    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 4; j++) {
            if (s[i][j] != '.') continue;
            s[i][j] = 'x';
            if (check()) {
                printf("YES");
                return 0;
            }
            s[i][j] = '.';
        }
    }

    printf("NO");

    return 0;
}
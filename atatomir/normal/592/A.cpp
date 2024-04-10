#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

int a, b;
char ch;

char s[10][10];
bool good[10];

int main()
{
    //freopen("test.in","r",stdin);

    a = b = 100;

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            scanf("%c", &ch); s[i][j] = ch;
            if (good[j] == true) continue;
            if (ch == 'W') a = min(a, i - 1);
            if (ch == 'B') good[j] = true;
        }
        scanf("\n");
    }

    memset(good, 0, sizeof(good));

    for (int i = 8; i >= 1; i--) {
        for (int j = 1; j <= 8; j++) {
            ch = s[i][j];
            if (ch == '.') continue;
            if (good[j]) continue;
            if (ch == 'W') good[j] = true;
            if (ch == 'B') b = min(b, 8 - i);
        }
    }

    //cerr << a << ' ' << b;

    if (a <= b) printf("A");
    else        printf("B");

    return 0;
}
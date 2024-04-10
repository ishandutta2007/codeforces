#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;

char s[120][102];
int use[120];
int n, _;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%s", s[i]);
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 10; ++j) use[j] = 0;
            bool f = false;
            for (int j = 0; j < i; ++j) {
                bool same = true;
                for (int k = 0; k < 4; ++k) if (s[i][k] != s[j][k]) same = false;
                if (same) f = true;
            }
            if (f) {
                for (int j = 0; j < n; ++j) use[s[j][0] - '0'] = 1;
                int id = -1;
                for (int j = 0; j < 10; ++j) if (!use[j]) id = j;
                s[i][0] = id + '0';
                ++ans;
            }
        }
        printf("%d\n", ans);
        for (int i = 0; i < n; ++i, puts(""))
            for (int j = 0; j < 4; ++j)
                printf("%c", s[i][j]);
    }
    return 0;
}

/*
3
2
1234
0600
2
1337
1337
4
3139
3139
3139
3139

*/
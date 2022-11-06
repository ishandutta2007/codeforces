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


const int V = 100100;

int s[3][V], n, Q, x, y;

int main() {
    while (~scanf("%d%d", &n, &Q)) {
        for (int i = 1; i <= n; ++i)
            s[2][i] = s[1][i] = 0;
        int cnt = 0;
        while (Q--) {
            scanf("%d%d", &x, &y);
            if (s[x][y] == 0) {
                for (int i = -1; i <= 1; ++i) {
                    if (y + i > 0 && y + i <= n && s[3 - x][y + i] == 1) cnt++;
                }
                s[x][y] = 1;
            } else {
                for (int i = -1; i <= 1; ++i) {
                    if (y + i > 0 && y + i <= n && s[3 - x][y + i] == 1) cnt--;
                }
                s[x][y] = 0;
            }
            if (cnt == 0) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}

/*
5 5
2 3
1 4
2 4
2 3
1 4
*/
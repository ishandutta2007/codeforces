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
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 5010;
int x[4 * V], y[4 * V];
char s[V];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int _;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%s", s);
        int n = strlen(s);
        int cx = 0, cy = 0;
        int m = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 4; ++j) {
                x[m] = cx + dx[j];
                y[m++] = cy + dy[j];
            }
            if (s[i] == 'L') cx--;
            else if (s[i] == 'R') cx++;
            else if (s[i] == 'U') cy++;
            else cy--;
        }
        int ax = 0, ay = 0;
        for (int j = 0; j < m; ++j) {
            cx = cy = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'L') cx--;
                else if (s[i] == 'R') cx++;
                else if (s[i] == 'U') cy++;
                else cy--;
                if (cx == x[j] && cy == y[j]) {
                    if (s[i] == 'L') cx++;
                    else if (s[i] == 'R') cx--;
                    else if (s[i] == 'U') cy--;
                    else cy++;
                }
            }
            if (cx == 0 && cy == 0) ax = x[j], ay = y[j];
        }
        printf("%d %d\n", ax, ay);
    }
    return 0;
}

/*
4
L
RUUDL
LLUU
DDDUUUUU
*/
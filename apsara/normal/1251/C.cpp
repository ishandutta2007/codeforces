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
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;

const int V = 300100;
char s[V];
int a[2][V], m[2] , _, n;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%s", s);
        n = strlen(s);
        m[0] = m[1] = 0;
        for (int i = 0; i < n; ++i) {
            int x = (s[i] - '0');
            a[x % 2][m[x % 2]++] = x;
        }
        int p0 = 0, p1 = 0;
        while (1) {
            if (p0 == m[0] && p1 == m[1]) break;
            if (p0 == m[0]) {
                printf("%d", a[1][p1++]);
            } else if (p1 == m[1]) {
                printf("%d", a[0][p0++]);
            } else if (a[0][p0] < a[1][p1]) {
                printf("%d", a[0][p0++]);
            } else {
                printf("%d", a[1][p1++]);
            }
        }
        puts("");
    }
    return 0;
}

/*
3
0709
1337
246432
*/
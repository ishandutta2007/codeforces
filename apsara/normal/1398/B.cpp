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
const int V = 120;
int _, a[V], n, m;
char s[V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%s", s);
        n = strlen(s);
        m = 0;
        s[n] = '0';
        int pre = 0;
        for (int i = 0; i <= n; ++i) {
            if (s[i] == '0') {
                if (pre == 0) continue;
                a[m++] = pre;
                pre = 0;
            } else {
                ++pre;
            }
        }
        sort(a, a + m);
        int ans = 0;
        for (int i = m - 1; i >= 0; i -= 2) ans += a[i];
        printf("%d\n", ans);
    }
    return 0;
}

/*
5
01111001
0000
111111
101010101
011011110111
*/
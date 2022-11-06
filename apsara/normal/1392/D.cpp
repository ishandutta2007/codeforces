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
const int V = 200100;
char s[V];
int _, n, m, a[V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        scanf("%s", s);
        int cnt = 0;
        m = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0 && s[i] != s[i - 1]) {
                a[m++] = cnt;
                cnt = 1;
            } else ++cnt;
        }
        a[m++] = cnt;
        if (m != 1 && s[0] == s[n - 1]) a[0] += a[--m];
        int ans = 0;
        if (m != 1) {
            for (int i = 0; i < m; ++i) {
                ans += a[i] / 3;
            }
        } else {
            if (a[0] >= 3) ans = (a[0] + 2) / 3;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
5
4
RLRL
6
LRRRRL
8
RLLRRRLL
12
LLLLRRLRRRLL
5
RRRRR
*/
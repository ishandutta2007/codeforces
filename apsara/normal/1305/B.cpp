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

const int V = 1100;
char s[V];
int pl[V], pr[V];
int main() {
    while (~scanf("%s", s)) {
        int n = strlen(s);
        for (int i = 1; i <= n; ++i) pl[i] = n + 1;
        for (int i = 1; i <= n; ++i) pr[i] = -1;
        int cl = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++cl;
                pl[cl] = i;
            }
        }
        int cr = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++cr;
                pr[cr] = i;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (pl[i] >= pr[i]) break;
            cnt = i;
        }
        if (cnt == 0) puts("0");
        else {
            puts("1");
            printf("%d\n", 2 * cnt);
            for (int i = 1; i <= cnt; ++i) printf("%d ", pl[i] + 1);
            for (int i = cnt; i >= 1; --i) printf("%d ", pr[i] + 1);
            puts("");
        }
    }
    return 0;
}

/*
(()((
)(
(()())
*/
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
const int V = 100100;
const int N = 26;
char s[V];
int last[30], mx[V], cnt[V][30], mi[V];
LL tmp[30][30];

int main() {
    while (~scanf("%s", s)) {
        int n = strlen(s);
        memset(last, -1, sizeof(last));
        memset(cnt, 0, sizeof(cnt));
        mi[n] = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < N; ++j)
                cnt[i][j] = cnt[i + 1][j];
            cnt[i][s[i] - 'a']++;
            mi[i] = max(mi[i + 1], cnt[i][s[i] - 'a']);
        }
        LL ans = mi[0];
        //for (int i = 0; i <= n; ++i) ans = max(ans, (LL) mx[i] * mi[i]);
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < N; ++j) {
                tmp[s[i] - 'a'][j] += cnt[i + 1][j];
            }
        }
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                ans = max(ans, tmp[i][j]);
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
aaabb
usaco
lol
*/
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

const int V = 200100;
char s[V * 5];
int vis[30];
int d[30][30];
int has[30];
int D[30];
const int N = 26;
int n;
int main() {
    while (~scanf("%d", &n)) {
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        for (int i = 0; i < n; ++i) {
            memset(has, 0, sizeof(has));
            scanf("%s", s);
            int m = strlen(s);
            for (int j = 0; j < m; ++j) has[s[j] - 'a'] = 1;
            for (int j = 0; j < N; ++j) {
                if (has[j]) {
                    vis[j] = 1;
                    for (int k = 0; k < N; ++k) {
                        if (has[k]) d[j][k] = 1;
                    }
                }
            }
        }
        for (int k = 0; k < N; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    if (d[i][k] && d[k][j]) d[i][j] = 1;
        int ans = 0;
        memset(D, 0, sizeof(D));
        for (int i = 0; i < N; ++i)
            if (vis[i] && !D[i]) {
                D[i] = 1;
                for (int j = 0; j < N; ++j)
                    if (d[i][j]) D[j] = 1;
                ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}

/*
4
a
b
ab
d
3
ab
bc
abc
1
codeforces
*/
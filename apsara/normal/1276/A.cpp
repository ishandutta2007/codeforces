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


const int V = 150100;
const int oo = 100000000;
char s[V];
int ans[V];
// 0 null
// 1 o
// 2 on
// 3 t
// 4 tw
// 5 false;
int tran(int x, char c) {
    if (x == 4 && c == 'o') return 5;
    if (x == 2 && c == 'e') return 5;
    if (c == 'o') return 1;
    if (x == 1 && c == 'n') return 2;
    if (c == 't') return 3;
    if (x == 3 && c == 'w') return 4;
    return 0;
}
const int M = 6;
int dp[V][6];
int pre[V][6];
int del[V][6];
int _;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%s", s);
        int n = strlen(s);
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j < M; ++j)
                dp[i][j] = oo, del[i][j] = 0;
        dp[0][0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < M; ++j) {
                if (dp[i][j] == oo) continue;
                //printf("DP %d %d %d\n", i,j, dp[i][j]);
                if (i == n) continue;
                if (dp[i + 1][j] > dp[i][j] + 1) {
                    dp[i + 1][j] = dp[i][j] + 1;
                    pre[i + 1][j] = j;
                    del[i + 1][j] = 1;
                }
                int x = tran(j, s[i]);
                if (x != 5) {
                    if (dp[i + 1][x] > dp[i][j]) {
                        dp[i + 1][x] = dp[i][j];
                        pre[i + 1][x] = j;
                        del[i + 1][x] = 0;
                    }
                }
            }
        }
        int mj, res = oo;
        for (int i = 0; i < M; ++i) {
            if (dp[n][i] < res) {
                res = dp[n][i];
                mj = i;
            }
        }
        int m = 0;
        int mi = n;
        //printf("res  %d\n", res);
        while (mi != 0) {
            if (del[mi][mj] == 1) ans[m++] = mi;
            mj = pre[mi][mj];
            --mi;
        }
        printf("%d\n", m);
        for (int i = 0; i < m; ++i) printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}

/*
4
onetwone
testme
oneoneone
twotwo

10
onetwonetwooneooonetwooo
two
one
twooooo
ttttwo
ttwwoo
ooone
onnne
oneeeee
oneeeeeeetwooooo

*/
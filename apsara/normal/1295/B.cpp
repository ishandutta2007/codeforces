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

const int V = 100100;
char t[V];
int s[V];
int _, n, K;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &K);
        scanf("%s", t);
        s[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (t[i] == '0') s[i + 1] = s[i] + 1;
            else s[i + 1] = s[i] - 1;
        }
        if (s[n] == 0) {
            bool has = false;
            for (int i = 0; i <= n; ++i) if (s[i] == K) has = true;
            if (has) {
                puts("-1");
            }
            else puts("0");
            continue;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int d = K - s[i];
            int num = d / s[n];
            if (num >= 0 && d % s[n] == 0) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
4
6 10
010010
5 3
10101
1 0
0
2 0
01

*/
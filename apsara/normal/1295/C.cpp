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
const int N = 26;

char s[V], t[V];
int _;
int ne[V][N];
int last[N];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%s%s", s, t);
        int n = strlen(s);
        int m = strlen(t);
        memset(last, -1, sizeof(last));
        for (int i = n; i >= 0; --i) {
            for (int j = 0; j < N; ++j)
                ne[i][j] = last[j];
            if (i != 0) last[s[i - 1] - 'a'] = i;
        }
        bool ok = true;
        int ans = 1;
        int cur = 0;
        for (int i = 0; i < m; ++i) {
            //printf("%d %d %d\n", i, cur, ne[cur][t[i] - 'a']);
            if (ne[cur][t[i] - 'a'] == -1) {
                cur = 0;
                ans++;
            }
            if (cur == 0 && ne[cur][t[i] - 'a'] == -1) {
                ok = false;
                break;
            }
            cur = ne[cur][t[i] - 'a'];
        }
        if (!ok) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}

/*
3
aabce
ace
abacaba
aax
ty
yyt
*/
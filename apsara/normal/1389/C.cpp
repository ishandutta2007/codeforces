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
const int N = 10;
char s[V];
int _, n, a[V];
int cnt[N + 5];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%s", s);
        n = strlen(s);
        for (int i = 0; i < n; ++i) a[i] = s[i] - '0';
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) cnt[a[i]]++;
        int ans = 0;
        for (int i = 0; i < N; ++i) ans = max(ans, cnt[i]);
        for (int i = 0; i < N; ++i) {
            if (cnt[i] == 0) continue;
            for (int j = 0; j < N; ++j) {
                if (cnt[j] == 0) continue;
                int st = 0;
                int tmp = 0;
                for (int k = 0; k < n; ++k) {
                    if (st == 0) {
                        if (a[k] == i) {
                            st = 1;
                        }
                    } else {
                        if (a[k] == j) {
                            st = 0;
                            ++tmp;
                            ans = max(ans, 2 * tmp);
                        }
                    }
                }
            }
        }
        printf("%d\n", n - ans);
    }
    return 0;
}

/*
3
95831
100120013
252525252525
*/
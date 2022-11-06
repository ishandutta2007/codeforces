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
const int N = 20;
int cnt[30];
int a[V], n;

int main() {
    while (~scanf("%d", &n)) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            for (int j = 0; j < N; ++j)
                if (a[i] & (1 <<j)) ++cnt[j];
        }
        LL ans = 0;
        for (int i = 0; i < n; ++i) {
            int tmp = 0;
            for (int j = N - 1; j >= 0; --j) {
                if (cnt[j] > 0) {
                    tmp |= (1 << j);
                    --cnt[j];
                }
            }
            ans += (LL) tmp * tmp;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*

*/
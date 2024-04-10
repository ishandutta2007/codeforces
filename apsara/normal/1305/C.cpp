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
int a[V], n, m;
int cnt[1200];
int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int ans = 1;
        if (n > m) ans = 0;
        else {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    ans = (LL)ans * abs(a[i] - a[j]) % m;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
2 10
8 5
3 12
1 4 5
3 7
1 4 9
*/
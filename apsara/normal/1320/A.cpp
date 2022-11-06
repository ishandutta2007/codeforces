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
map<int, LL> mp;
int b[V], n;

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
        mp.clear();
        LL ans = 0;
        for (int i = 1; i <= n; ++i) {
            int diff = i - b[i];
            LL pre = 0;
            if (mp.find(diff) != mp.end()) {
                pre = max(pre, mp[i - b[i]]);
            }
            mp[i - b[i]] = pre + b[i];
            ans = max(ans, pre + b[i]);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
6
10 7 1 9 10 15
1
400000
7
8 9 26 11 12 29 14
*/
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

int _, a, b, c, d, n;
map<PII, int> mp;
int main() {
    scanf("%d", &_);
    while (_--) {
        mp.clear();
        scanf("%d", &n);
        LL ans = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            c -= a; d -= b;
            int g = __gcd(abs(c), abs(d));
            c /= g; d /= g;
            if (mp.find({-c, -d}) != mp.end()) ans += mp[{-c, -d}];
            int cnt = 1;
            if (mp.find({c, d}) != mp.end()) cnt += mp[{c, d}];
            mp[{c, d}] = cnt;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
3
2
0 0 0 1
1 0 2 0
3
0 0 1 1
1 1 0 0
1 0 2 0
6
0 0 0 1
1 0 1 2
2 0 2 3
3 0 3 -5
4 0 4 -5
5 0 5 -5
*/
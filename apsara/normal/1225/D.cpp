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
const int N = 100100;
vector<PII> fac[V];
map<vector<int>, int> mp;

int n, K, x;
int main() {
    for (int i = 1; i <= N; ++i) {
        fac[i].PB(MP(1, 0));
        x = i;
        for (int j = 2; j * j <= x; ++j) {
            if (x % j == 0) {
                int cnt = 0;
                while (x % j == 0) ++cnt, x /= j;
                fac[i].PB(MP(j, cnt));
            }
        }
        if (x != 1) fac[i].PB(MP(x, 1));
    }
    while (~scanf("%d%d", &n, &K)) {
        mp.clear();
        LL ans = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            vector<int> new_f, need_f;
            for (auto f : fac[x]) {
                if (f.fi == 1 || f.se % K != 0) {
                    new_f.PB(f.fi), new_f.PB(f.se % K);
                    need_f.PB(f.fi), need_f.PB((K - f.se % K) % K);
                }
            }
            //for (auto f : new_f) printf("%d ", f); puts("new");
            //for (auto f : need_f) printf("%d ", f); puts("need");
            if (mp.find(need_f) != mp.end()) ans += mp[need_f];
            if (mp.find(new_f) != mp.end()) mp[new_f]++;
            else mp[new_f] = 1;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
6 3
1 3 9 8 24 1

*/
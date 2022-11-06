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
const int V = 100100;
int _, n, a[V];
char t[V];
map<int, int> mp;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        scanf("%s", t);
        for (int i = 1; i <= n; ++i) a[i] = t[i - 1] - '0';
        LL ans = 0;
        mp.clear();
        int s = 0;
        mp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            s += a[i] - 1;
            int cnt = 1;
            if (mp.find(s) != mp.end()) ans += mp[s], cnt += mp[s];
            mp[s] = cnt;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
3
3
120
5
11011
6
600005
*/
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

int _, n, a[100100];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int mx = a[0];
        int md = 0;
        for (int i = 0; i < n; ++i) {
            md = max(md, mx - a[i]);
            mx = max(a[i], mx);
        }
        int ans = 0;
        while (md) {
            ++ans;
            md /= 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
3
4
1 7 6 5
5
1 2 3 4 5
2
0 -4
*/
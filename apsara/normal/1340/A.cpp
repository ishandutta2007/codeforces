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
int _, n, a[V], pos[V], use[V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) pos[a[i]] = i;
        for (int i = 1; i <= n; ++i) use[i] = 0;
        int pre = -1;
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            if (pre == -1 || pre == pos[i] - 1 || (pre == n || use[pre + 1] == 1)) {
                use[pos[i]] = 1;
                pre = pos[i];
            } else {
                ok = false;
                break;
            }
        }
        if (ok) puts("Yes");
        else puts("No");
    }
    return 0;
}

/*
5
5
2 3 4 5 1
1
1
3
1 3 2
4
4 2 3 1
5
1 5 2 4 3
*/
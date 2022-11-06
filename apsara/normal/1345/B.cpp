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
const int N = 1000000000;

int f[31000], _, n;

int main() {
    int MX = 1;
    for (int i = 1; ; ++i) {
        f[i] = i * (1 + i) / 2 * 3 - i;
        if (f[i] > N) break;
        MX = i;
    }
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        int ans = 0;
        for (int i = MX; i >= 1; --i) {
            while (n >= f[i]) {
                ++ans;
                n -= f[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*

*/
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
int a, b, n, _;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d", &a, &b, &n);
        int ans = 0;
        while (1) {
            if (a > n || b > n) break;
            ++ans;
            if (a < b) a += b;
            else b += a;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
2
1 2 3
5 4 100
*/
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
int a, b, ans, _;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &a, &b);
        ans = min(a, b);
        ans = min(ans, (a + b) / 3);
        printf("%d\n", ans);
    }
    return 0;
}

/*
4
4 4
1000000000 0
7 15
8 7
*/
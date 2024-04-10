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

int _, a, b;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &a, &b);
        if (b == 1) {
            puts("NO");
            continue;
        }
        puts("YES");
        printf("%I64d %I64d %I64d\n", (LL) a, (LL) a * (b + b - 1), (LL) a * b * 2);
    }
    return 0;
}

/*
3
5 3
13 2
7 11
*/
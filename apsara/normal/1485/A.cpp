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
        int ans = 1e9;
        for (int i = 0; i <= 40; ++i) {
            int c = b + i;
            if (c == 1) continue;
            int d = a;
            int tmp = i;
            while (d > 0) {d /= c; ++tmp;}
            ans = min(ans, tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
6
9 2
1337 1
1 1
50000000 4
991026972 997
1234 5678
*/
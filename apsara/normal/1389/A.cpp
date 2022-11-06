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

int _, L, R;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &L, &R);
        if (R < 2 * L) {
            puts("-1 -1");
        } else {
            printf("%d %d\n", L, 2 * L);
        }
    }
    return 0;
}

/*
4
1 1337
13 69
2 4
88 89
*/
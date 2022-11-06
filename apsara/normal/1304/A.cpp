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
int _, x, y, a, b;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d%d", &x, &y, &a, &b);
        int d = (y - x) / (a + b);
        if ((y - x) % (a + b) != 0) d = -1;
        printf("%d\n", d);
    }
    return 0;
}

/*
5
0 10 2 3
0 10 3 3
900000000 1000000000 1 9999999
1 2 1 1
1 3 1 1
*/
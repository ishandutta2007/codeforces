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

int _, a, b, c;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d", &a, &b, &c);
        if (c == 0) {
            if (a == b) puts("YES");
            else puts("NO");
        } else {
            int d = (abs(a - b) + c - 1) / c;
            if (d <= min(a, b)) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}

/*
4
1 1 0
2 7 3
6 1 4
5 4 0
*/
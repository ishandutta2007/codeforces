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
const int V = 61;
int _, n, x;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        int ans = n;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            if (x == 2) --ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
4
1
2
3
1 2 3
5
1 1 1 1 1
3
3 3 2
*/
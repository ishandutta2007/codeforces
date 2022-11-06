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
const int V = 200100;
int _, n, m;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i < 2 * m - n; ++i) printf("%d ", i);
        for (int i = m; i >= 2 * m - n; --i) printf("%d ", i); puts("");
    }
    return 0;
}

/*
4
1 1
2 2
3 2
4 3
*/
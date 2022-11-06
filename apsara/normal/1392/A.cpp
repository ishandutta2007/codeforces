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
int _, n, a[V];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int mi = a[0], mx = a[0];
        for (int i = 0; i < n; ++i) mi = min(mi, a[i]), mx = max(mx, a[i]);
        if (mi == mx) printf("%d\n", n);
        else puts("1");
    }
    return 0;
}

/*
2
4
2 1 3 1
2
420 420
*/
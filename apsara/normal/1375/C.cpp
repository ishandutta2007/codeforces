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
const int V = 300100;

int _, n, a[V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        if (a[1] < a[n]) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
4
3
1 2 3
4
3 1 2 4
3
2 3 1
6
2 4 6 1 3 5
*/
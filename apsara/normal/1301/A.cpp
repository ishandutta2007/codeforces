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
const int V = 100100;
char a[V], b[V], c[V];

int n, _;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%s%s%s", a, b, c);
        n = strlen(a);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] != c[i] && b[i] != c[i]) ok = false;
        }
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
4
aaa
bbb
ccc
abc
bca
bca
aabb
bbaa
baba
imi
mii
iim
*/
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

int a[V], _, n;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        a[0] = 9;
        a[1] = 8;
        for (int i = 2; i < n; ++i) a[i] = (a[i - 1] + 1) % 10;
        for (int i = 0; i < n; ++i) printf("%d", a[i]); puts("");
    }
    return 0;
}

/*
2
1
2
*/
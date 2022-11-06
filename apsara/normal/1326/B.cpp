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
int b[V], a[V], n;
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            a[i] = b[i] + mx;
            mx = max(a[i], mx);
        }
        for (int i = 0; i < n; ++i) printf("%d ", a[i]);puts("");
    }
    return 0;
}

/*

*/
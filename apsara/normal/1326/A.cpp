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
int _, n;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        if (n == 1) {
            puts("-1");
            continue;
        }
        printf("2");
        for (int i = 1; i < n; ++i) printf("3"); puts("");
    }
    return 0;
}

/*

*/
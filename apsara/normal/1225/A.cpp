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

using namespace std;
typedef long long LL;
const int P = 1000000007;

int a, b;
int main() {
    while (~scanf("%d%d", &a, &b)) {
        if (a == 9 && b == 1) {
            puts("9 10");
            continue;
        }
        if (a > b || a + 1 < b) {
            puts("-1");
            continue;
        }
        if (a + 1 == b) printf("%d9 %d0\n", a, b);
        else printf("%d0 %d1\n", a, b);
    }
    return 0;
}

/*

*/
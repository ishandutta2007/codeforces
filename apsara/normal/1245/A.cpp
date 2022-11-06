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

int gcd(int x, int y) {
    if (!y) return x;
    return gcd(y, x % y);
}

int _, a, b;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &a, &b);
        int gd = gcd(a, b);
        if (gd == 1) puts("Finite");
        else puts("Infinite");
    }
    return 0;
}

/*

*/
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

int _, a[120];
int main() {
    scanf("%d", &_);
    while (_--) {
       for (int i = 0; i < 3; ++i) scanf("%d", &a[i]);
       sort(a, a + 3);
       int x = a[0] + a[1];
       int y = a[2];
       int ans = (x + min(x, y)) / 2;
       printf("%d\n", ans);
    }
    return 0;
}

/*
6
1 1 1
1 2 1
4 1 1
7 4 10
8 1 4
8 2 8

*/
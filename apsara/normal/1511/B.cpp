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
int _, a, b, c;
int main() {
    scanf("%d", &_);
    /*
    for (int A = 1; A <= 9; ++A)
        for (int B = 1; B <= A; ++B)
    for (int C = 1; C <= B; ++C) { a = A, b = B, c = C;
        */
    while (_--) {
        scanf("%d%d%d", &a, &b, &c);
        int z = 1;
        for (int i = 1; i < c; ++i) z *= 10;
        a -= c; b -= c;
        int x = 1;
        for (int i = 0; i < a; ++i) x *= 10;
        if (a >= 1) x += 9;
        int y = 1;
        for (int i = 0; i < b; ++i) y *= 10;
        if (b >= 1) y += 9;
        if (a == b) y++;
        printf("%d %d\n", x * z, y * z);
        //if(__gcd(x * z, y * z)!= z)printf("%d %d %d %d %d %d %d\n", a, b, c, x * z, y * z, __gcd(x * z, y * z), z);
    }
    return 0;
}

/*
4
2 3 1
2 2 2
6 6 2
1 1 1
*/
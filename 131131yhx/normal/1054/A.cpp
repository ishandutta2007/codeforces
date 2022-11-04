#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <bitset>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

int x, y, z, t1, t2, t3;

int Abs(int x) {
    return x < 0 ? -x : x;
}

int main() {
    scanf("%d%d%d%d%d%d", &x, &y, &z, &t1, &t2, &t3);
    int A = Abs(x - y) * t1;
    int B = 3 * t3 + t2 * (Abs(x - z) + Abs(x - y));
    if(B <= A) puts("YES"); else puts("NO");
    return 0;
}
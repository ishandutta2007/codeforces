#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int ax, ay, bx, by, cx, cy, B, C;
    scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
    B = 0;
    C = 0;
    if(bx < ax) B++;
    if(by < ay) B += 2;
    if(cx < ax) C++;
    if(cy < ay) C += 2;
    puts(B == C ? "YES" : "NO");
    return 0;
}
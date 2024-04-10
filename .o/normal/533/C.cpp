#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


int main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
#endif
    int xp, yp, xv, yv;

    scanf("%d%d%d%d", &xp, &yp, &xv, &yv);

    // Polycarp : (x,y) -> (x-1, y) or (x, y-1)
    // Vasiliy: (x,y) -> (x-1,y), (x-1,y-1) or (x, y-1)

    puts((xp <= xv && yp <= yv) || (xp + yp <= max(xv, yv)) ? "Polycarp" : "Vasiliy");
    return 0;
}
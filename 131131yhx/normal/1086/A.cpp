#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#define int long long
#define P 1000000000

using namespace std;

typedef long long ll;

int Abs(int x) {return x < 0 ? -x : x;}

bool A[1010][1010];

signed main() {
    int xa, ya, xb, yb, xc, yc, ans = 1e9, ans1, ans2;
    scanf("%lld%lld%lld%lld%lld%lld", &xa, &ya, &xb, &yb, &xc, &yc);
    int x = xa + xb + xc - max(max(xa, xb), xc) - min(min(xa, xb), xc);
    int y = ya + yb + yc - max(max(ya, yb), yc) - min(min(ya, yb), yc);
    for(int i = xa; i <= x; i++) A[i][ya] = 1;
    for(int i = xb; i <= x; i++) A[i][yb] = 1;
    for(int i = xc; i <= x; i++) A[i][yc] = 1;
    for(int i = xa; i >= x; i--) A[i][ya] = 1;
    for(int i = xb; i >= x; i--) A[i][yb] = 1;
    for(int i = xc; i >= x; i--) A[i][yc] = 1;
    for(int i = ya; i <= y; i++) A[x][i] = 1;
    for(int i = yb; i <= y; i++) A[x][i] = 1;
    for(int i = yc; i <= y; i++) A[x][i] = 1;
    for(int i = ya; i >= y; i--) A[x][i] = 1;
    for(int i = yb; i >= y; i--) A[x][i] = 1;
    for(int i = yc; i >= y; i--) A[x][i] = 1;
    
    int tot = 0;
    for(int i = 0; i <= 1000; i++)
        for(int j = 0; j <= 1000; j++)
            if(A[i][j]) tot++;
    printf("%lld\n", tot);
    for(int i = 0; i <= 1000; i++)
        for(int j = 0; j <= 1000; j++)
            if(A[i][j]) printf("%lld %lld\n", i, j);
    return 0;
}
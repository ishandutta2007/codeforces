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
#define M 200010

using namespace std;

typedef long long ll;

int Head[M], Next[M], Go[M], D[M], Cnt = 0, n;

double s;

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
}

signed main() {
    scanf("%lld%lf", &n, &s);
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        addedge(a, b);
        addedge(b, a);
        D[a]++, D[b]++;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) cnt += D[i] == 1;
    printf("%.12lf\n", s / cnt * 2);
    return 0;
}
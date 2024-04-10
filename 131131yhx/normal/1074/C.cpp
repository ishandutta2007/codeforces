#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <queue>
#include <bitset>
#include <cmath>

using namespace std;

struct node {
    int x, y;
    node() {}
    node(int _1, int _2) {x = _1, y = _2;}
} X[600010], Y[600010];

int n;

bool cmpy(node x, node y) {return x.y > y.y;}
bool cmpx(node x, node y) {return x.x > y.x;}
    
int solve3() {
    for(int i = n + 1; i <= 2 * n; i++) X[i] = X[i - n];
    int mxy = -1e9, v;
    for(int i = 1; i <= n; i++) if(X[i].y > mxy) mxy = X[i].y, v = i;
    for(int i = v; i < v + n; i++) Y[i - v + 1] = X[i];
    Y[n + 1] = Y[1];
    int mny = 1e9, v1;
    for(int i = 1; i <= n; i++) if(Y[i].y < mny) mny = Y[i].y, v1 = i;
    int mnx = 1e9, v2;
    for(int i = 2; i <= n + 1; i++) if(Y[i].x < mnx) mnx = Y[i].x, v2 = i;
    vector <node> V1(0), V2(0);
    for(int i = v1; i <= v2; i++) V1.push_back(Y[i]);
    for(int i = v2; i >= v1; i--) V2.push_back(Y[i]);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int x = X[i].x, y = X[i].y;
        int xx = V2[lower_bound(V2.begin(), V2.end(), X[i], cmpy) - V2.begin()].x;
        int yy = V1[lower_bound(V1.begin(), V1.end(), X[i], cmpx) - V1.begin()].y;
        ans = max(ans, x - xx + y - yy);
    }
    return ans * 2;
}

int Solve3() {
    int ans = solve3();
    for(int i = 1; i <= n; i++) X[i].x *= -1;
    reverse(X + 1, X + n + 1);
    ans = max(ans, solve3());
    for(int i = 1; i <= n; i++) X[i].y *= -1;
    reverse(X + 1, X + n + 1);
    ans = max(ans, solve3());
    for(int i = 1; i <= n; i++) X[i].x *= -1;
    reverse(X + 1, X + n + 1);
    return max(ans, solve3());
}

int Solve4() {
    int mxx = -1e9, mnx = 1e9, mxy = -1e9, mny = 1e9;
    for(int i = 1; i <= n; i++) {
        mxx = max(mxx, X[i].x);
        mnx = min(mnx, X[i].x);
        mxy = max(mxy, X[i].y);
        mny = min(mny, X[i].y);
    }
    return 2 * (mxx - mnx) + 2 * (mxy - mny);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d", &X[i].x, &X[i].y);
    printf("%d ", Solve3());
    int ans4 = Solve4();
    for(int i = 4; i <= n; i++) printf("%d ", ans4);
    putchar('\n');
    return 0;
}
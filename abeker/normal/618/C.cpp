#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

int N;
int x[MAXN], y[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", x + i, y + i);
}

ll ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (ll)x1 * (y2 - y3) + (ll)x2 * (y3 - y1) + (ll)x3 * (y1 - y2);
}

void solve() {
    int pos = -1, val = (int)2e9;
    for (int i = 1; i < N; i++)
        if (x[i] != x[0] && abs(x[i] - x[0]) <= val) {
            pos = i;
            val = abs(x[i] - x[0]);
        }
    
    int idx = -1;
    ll mini = (ll)7e18;
    for (int i = 0; i < N; i++) {
        ll area = abs(ccw(x[0], y[0], x[pos], y[pos], x[i], y[i]));
        if (area > 0 && area < mini) {
            mini = area;
            idx = i;
        } 
    }
    
    printf("%d %d %d\n", 1, pos + 1, idx + 1);
}

int main() {
    load();
    solve();
    return 0;
}
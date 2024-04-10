#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long i64;
const double eps = 1e-10;

bool good(i64 x1, i64 y1, i64 x2, i64 y2, i64 A2, i64 B2, i64 C2) {
    i64 A1 = (y2 - y1);
    i64 B1 = (x1 - x2);
    i64 C1 = -(x1 * y2 - x2 * y1);
    i64 det = A1 * B2  - A2 * B1;
    if (det == 0) return false;
    double x = -(C1 * B2 - C2 * B1) / (double) det;
    double y = -(A1 * C2 - A2 * C1) / (double) det;
    if (x + eps > min(x1, x2) && x - eps < max(x1, x2) && y + eps > min(y1, y2) && y - eps < max(y1, y2)) return true;
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    int N;
    scanf("%d", &N);

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        int A, B, C;
        scanf("%d%d%d", &A, &B, &C);
        if (good(x1, y1, x2, y2, A, B, C))
            ++ans;
    }

    printf("%d\n", ans);
}
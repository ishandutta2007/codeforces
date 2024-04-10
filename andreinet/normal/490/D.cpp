#include <algorithm>
#include <cstdio>

using namespace std;

int getDivs(int N, int div) {
    int ret = 0;
    while (N % div == 0) {
        N /= div;
        ret++;
    }
    return ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int X1, Y1, X2, Y2;
    scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);

    int f21 = getDivs(X1, 2) + getDivs(Y1, 2);
    int f31 = getDivs(X1, 3) + getDivs(Y1, 3);
    int f22 = getDivs(X2, 2) + getDivs(Y2, 2);
    int f32 = getDivs(X2, 3) + getDivs(Y2, 3);

    int cnt = 0;
    while (f32 > f31) {
        --f32;
        ++f22;
        int& c = (X2 % 3 != 0) ? Y2: X2;
        c = c / 3 * 2;
        ++cnt;
    }
    while (f31 > f32) {
        --f31;
        ++f21;
        int& c = (X1 % 3 != 0) ? Y1: X1;
        c = c / 3 * 2;
        ++cnt;
    }
    while (f22 > f21) {
        --f22;
        int& c = (X2 % 2 != 0) ? Y2: X2;
        c = c / 2;
        ++cnt;
    }
    while (f21 > f22) {
        --f21;
        int& c = (X1 % 2 != 0) ? Y1: X1;
        c = c / 2;
        ++cnt;
    }
    if (1LL * X1 * Y1 != 1LL * X2 * Y2) puts("-1");
    else printf("%d\n%d %d\n%d %d\n", cnt, X1, Y1, X2, Y2);
}
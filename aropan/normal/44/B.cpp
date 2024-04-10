#include <cstdio>

using namespace std;

int n, a, b, c;
int ans;

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d %d %d %d", &n, &a, &b, &c);
    for (int i = 0; i <= b; i++)
        for (int j = 0; j <= c; j++)
        {
            int m = n - i - 2 * j;
            if (m < 0) continue;
            ans += a >= m * 2;
        }
    printf("%d\n", ans);
    return 0;
}
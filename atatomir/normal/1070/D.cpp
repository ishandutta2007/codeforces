#include <fstream>

using namespace std;

int N, K;
long long s = 0, ans = 0;

int main()
{
//    freopen("K.in", "r", stdin);
//    freopen("K.out", "w", stdout);

    scanf ("%d %d", &N, &K);
    for (int i=1; i<=N; i++)
    {
        int x;
        scanf ("%d", &x);
        if (s == 0) ans += x / K, s = x % K;
        else
        {
            if (x + s < K) ans ++, s = 0;
            else s += x, ans += (s / K), s %= K;
        }
    }
    printf ("%I64d\n", ans + (s > 0));
    return 0;
}
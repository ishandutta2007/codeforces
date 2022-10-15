#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100001;

int x[MAXN], y[MAXN];
int n;

long long calc(int x[MAXN])
{
    sort(x, x + n);

    long long ans = 0;
    long long s = 0, ss = 0;
    for (long long i = 0; i < n; i++)
    {
        ans += i * x[i] * x[i] - s * 2 * x[i] + ss;

        s += x[i];
        ss += (long long)x[i] * x[i];
    }
    return ans;
}

int main()
{
    #ifdef OFFLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &x[i], &y[i]);

    printf("%I64d\n", calc(x) + calc(y));
    return 0;
}
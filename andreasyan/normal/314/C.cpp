#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006, M = 1000000007;

int n;
int a[N];

int q[N];

int t[N];
void ubd(int x, int y)
{
    while (x < N)
    {
        t[x] = (t[x] + y) % M;
        x += (x & (-x));
    }
}
int qry(int x)
{
    int ans = 0;
    while (x)
    {
        ans = (ans + t[x]) % M;
        x -= (x & (-x));
    }
    return ans;
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        int qq = q[a[i]];
        q[a[i]] = ((qry(a[i]) * 1LL * a[i]) % M + a[i]) % M;
        ubd(a[i], ((-qq + M) % M + q[a[i]]) % M);
    }
    printf("%d\n", qry(N - 1));
    return 0;
}
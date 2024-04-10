#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1003, M = 1000000007;

int c[N][N];

int n, k;
int a[N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    int qm = 0;
    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == a[k])
            ++q;
        else if (a[i] > a[k])
            ++qm;
    }

    printf("%d\n", c[q][k - qm]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    //ios_base::sync_with_stdio(false), cin.tie(0);

    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % M;
    }

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}
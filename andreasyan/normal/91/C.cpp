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
const int N = 100005, M = 1000000009;

int ast[N];

void pre()
{
    ast[0] = 1;
    for (int i = 1; i < N; ++i)
        ast[i] = (ast[i - 1] * 2) % M;
}

int n, m;

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (fi(x) == fi(y))
        {
            ++ans;
        }
        else
            kpc(x, y);
        printf("%d\n", (ast[ans] - 1 + M) % M);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
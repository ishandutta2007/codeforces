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
const int N = 1000006;

int n, qq;

int t[N];

void ubd(int x, int y)
{
    while (x <= n)
    {
        t[x] += y;
        x += (x & (-x));
    }
}

int qry(int x)
{
    int ans = 0;
    while (x)
    {
        ans += t[x];
        x -= (x & (-x));
    }
    return ans;
}

void solv()
{
    scanf("%d%d", &n, &qq);
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        ubd(x, 1);
    }
    for (int i = 0; i < qq; ++i)
    {
        int x;
        scanf("%d", &x);
        if (x > 0)
            ubd(x, 1);
        else
        {
            x *= -1;
            int l = 1, r = n;
            int ans;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (qry(m) >= x)
                {
                    ans = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            ubd(ans, -1);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (qry(i))
        {
            printf("%d\n", i);
            return;
        }
    }
    printf("0\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
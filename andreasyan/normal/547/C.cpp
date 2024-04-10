#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 500005;

int n, m;
int a[N];
bool c[N];

vector<int> v[N];
int q[N];

long long ans;

int stg(int i)
{
    int yans = 0;
    for (int x = 0; x < (1 << v[i].size()); ++x)
    {
        int u = 1;
        int b = 0;
        for (int j = 0; j < v[i].size(); ++j)
        {
            if ((x & (1 << j)))
            {
                ++b;
                u *= v[i][j];
            }
        }
        if (b % 2 == 0)
            yans += q[u];
        else
            yans -= q[u];
    }
    return yans;
}

void ave(int i)
{
    ans += stg(i);
    for (int x = 0; x < (1 << v[i].size()); ++x)
    {
        int u = 1;
        for (int j = 0; j < v[i].size(); ++j)
        {
            if ((x & (1 << j)))
            {
                u *= v[i][j];
            }
        }
        ++q[u];
    }
}

void han(int i)
{
    for (int x = 0; x < (1 << v[i].size()); ++x)
    {
        int u = 1;
        for (int j = 0; j < v[i].size(); ++j)
        {
            if ((x & (1 << j)))
            {
                u *= v[i][j];
            }
        }
        --q[u];
    }
    ans -= stg(i);
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    c[0] = c[1] = true;
    for (int i = 2; i < N; ++i)
    {
        if (c[i])
            continue;
        for (int j = i; j < N; j += i)
        {
            if (j != i)
                c[j] = true;
            v[j].push_back(i);
        }
    }
    memset(c, false, sizeof c);
    while (m--)
    {
        int i;
        scanf("%d", &i);
        if (c[i])
            han(a[i]);
        else
            ave(a[i]);
        c[i] ^= true;
        printf("%lld\n", ans);
    }
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
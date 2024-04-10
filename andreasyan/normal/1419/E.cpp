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

void solv()
{
    int n;
    scanf("%d", &n);
    int cn = n;

    vector<int> v;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 1)
        v.push_back(n);
    n = cn;

    vector<int> d;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            if (i > 1)
                d.push_back(i);
            if (i * i != n)
                d.push_back(n / i);
        }
    }

    if (sz(v) == 1)
    {
        for (int i = 0; i < sz(d); ++i)
            printf("%d ", d[i]);
        printf("\n");
        printf("0\n");
        return;
    }
    if (sz(v) == 2)
    {
        if (v[0] * v[1] == n)
        {
            for (int i = 0; i < sz(d); ++i)
                printf("%d ", d[i]);
            printf("\n");
            printf("1\n");
            return;
        }
        vector<int> u[33];
        for (int i = 0; i < sz(d); ++i)
        {
            if (d[i] == v[0] || d[i] == v[1] || d[i] == v[0] * v[1] || d[i] == n)
                continue;
            for (int j = 0; j < sz(v); ++j)
            {
                if (d[i] % v[j] == 0)
                {
                    u[j].push_back(d[i]);
                    break;
                }
            }
        }
        for (int i = 0; i < sz(v); ++i)
        {
            printf("%d ", v[i]);
            for (int j = 0; j < u[i].size(); ++j)
                printf("%d ", u[i][j]);
            if (i == 0)
                printf("%d ", v[i] * v[i + 1]);
        }
        printf("%d\n", n);
        printf("0\n");
        return;
    }

    vector<int> u[33];
    for (int i = 0; i < sz(d); ++i)
    {
        bool z = false;
        for (int j = 0; j < sz(v); ++j)
        {
            if (d[i] == v[j] * v[(j + 1) % sz(v)])
            {
                z = true;
                break;
            }
        }
        if (z)
            continue;
        for (int j = 0; j < sz(v); ++j)
        {
            if (d[i] % v[j] == 0)
            {
                u[j].push_back(d[i]);
                break;
            }
        }
    }
    for (int i = 0; i < sz(v); ++i)
    {
        for (int j = 0; j < u[i].size(); ++j)
            printf("%d ", u[i][j]);
        printf("%d ", v[i] * v[(i + 1) % sz(v)]);
    }
    printf("\n");
    printf("0\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}
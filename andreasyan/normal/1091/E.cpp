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
const int N = 500005;

int n;
int a[N];

int m;
int b[N];

ll p[N];

int stg(int x)
{
    bool z = false;
    m = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!z && x >= a[i])
        {
            b[++m] = x;
            z = true;
        }
        b[++m] = a[i];
    }
    if (!z)
    {
        b[++m] = x;
        z = true;
    }
    for (int i = 1; i <= m; ++i)
    {
        p[i] = p[i - 1] + b[i];
    }
    ll s = 0;
    int j = -1;
    for (int k = m - 1; k >= 1; --k)
    {
        s += min(b[k + 1], k + 1);
        if (j == -1)
        {
            if (b[k + 1] > k)
            {
                j = k + 1;
            }
        }
        if (j != -1)
        {
            while (j < m && b[j + 1] > k)
                ++j;
        }
        if (j != -1)
            s -= (j - k);
        s += k * 1LL * (k - 1);
        if (p[k] > s)
        {
            if (x >= b[k])
                return 1;
            else
                return -1;
        }
        s -= k * 1LL * (k - 1);
    }
    return 0;
}

void solv()
{
    scanf("%d", &n);
    ll s = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        s += a[i];
    }
    vector<int> v;
    if (s % 2 == 0)
    {
        for (int i = 0; i <= n; i += 2)
            v.push_back(i);
    }
    else
    {
        for (int i = 1; i <= n; i += 2)
            v.push_back(i);
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int l = 0, r = sz(v) - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        int u = stg(v[m]);
        if (u == -1)
        {
            l = m + 1;
        }
        else if (u == 1)
        {
            r = m - 1;
        }
        else
        {
            l = m, r = sz(v) - 1;
            int ansr;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (stg(v[m]) == 0)
                {
                    ansr = m;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            l = 0, r = m;
            int ansl;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (stg(v[m]) == 0)
                {
                    ansl = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            for (int i = ansl; i <= ansr; ++i)
                printf("%d ", v[i]);
            printf("\n");
            return;
        }
    }
    printf("-1\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
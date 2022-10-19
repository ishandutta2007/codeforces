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
const int N = 2000006;

int n, k;
char a[N];
int p[N];

bool c[N];

int q[22][N];

void solv()
{
    scanf("%d%d", &n, &k);
    scanf(" %s", (a + 1));

    for (int i = 1; i <= n; ++i)
        c[i] = false;
    for (int i = 1; i <= n; ++i)
        p[i] = (p[i - 1] + (a[i] == '0'));
    if (k > 20)
    {
        for (int i = 1; i <= n - k + 1; ++i)
        {
            int l = i;
            int r = l + k - 1;
            if (p[r - 20] - p[l - 1] > 0)
                c[i] = true;
        }
    }

    //if (k <= 20)
    {
        vector<int> v;
        for (int i = 1; i <= n - k + 1; ++i)
        {
            if (c[i])
                continue;

            int x = 0;
            int s = i + k - 1 - min(k, 20) + 1;
            for (int j = s; j <= i + k - 1; ++j)
            {
                if (a[j] == '1')
                    x += (1 << (j - s));
            }
            v.push_back(x);
        }
        sort(all(v));
        for (int i = 0; i < sz(v); ++i)
        {
            if (!i || v[i] != v[i - 1])
            {
                int u = 0;
                q[0][0]++;
                for (int j = 0; j < min(k, 20); ++j)
                {
                    u += (1 << j);
                    q[j + 1][(v[i] & u)]++;
                }
            }
        }

        if (k <= 20 && q[0][0] == (1 << k))
        {
            printf("NO\n");
            for (int i = 0; i < sz(v); ++i)
            {
                if (!i || v[i] != v[i - 1])
                {
                    int u = 0;
                    q[0][0] = 0;
                    for (int j = 0; j < k; ++j)
                    {
                        u += (1 << j);
                        q[j + 1][(v[i] & u)] = 0;
                    }
                }
            }
            return;
        }

        printf("YES\n");

        for (int i = 0; i < k - 20; ++i)
            printf("0");
        k = min(k, 20);

        int i = 0;
        int x = 0;
        while (i < k)
        {
            if (i == 19)
                printf("");
            if (q[i + 1][x + (1 << i)] != (1 << (k - i - 1)))
            {
                printf("0");
                x += (1 << i);
                ++i;
                continue;
            }
            printf("1");
            ++i;
        }
        printf("\n");
        for (int i = 0; i < sz(v); ++i)
        {
            if (!i || v[i] != v[i - 1])
            {
                int u = 0;
                q[0][0] = 0;
                for (int j = 0; j < k; ++j)
                {
                    u += (1 << j);
                    q[j + 1][(v[i] & u)] = 0;
                }
            }
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}
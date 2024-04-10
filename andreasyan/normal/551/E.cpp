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
const int N = 500005, s = 700, INF = 1000000009;

int ka()
{
    int x = 0;
    while (1)
    {
        char y = getchar();
        if ('0' <= y && y <= '9')
            x = x * 10 + y - '0';
        else
            return x;
    }
}

int n, qq;

int a[N];

int ave[N / s + 10];
vector<int> t[N / s + 10];

void solv()
{
    n = ka();
    qq = ka();
    for (int i = 1; i <= n; ++i)
        a[i] = ka();
    for (int i = 1; i <= n; ++i)
        t[i / s].push_back(a[i]);
    for (int i = 1 / s; i <= n / s; ++i)
        sort(all(t[i]));
    while (qq--)
    {
        int ty;
        ty = ka();
        if (ty == 1)
        {
            int l, r, x;
            l = ka();
            r = ka();
            x = ka();
            for (int i = l / s + 1; i <= r / s - 1; ++i)
            {
                ave[i] = min(INF, ave[i] + x);
            }
            if (l / s == r / s)
            {
                t[l / s].clear();
                for (int i = max(l / s * s, 1); i <= n && i / s == l / s; ++i)
                    a[i] = min(a[i] + ave[l / s], INF);
                ave[l / s] = 0;
                for (int i = l; i <= r; ++i)
                    a[i] = min(a[i] + x, INF);
                for (int i = max(l / s * s, 1); i <= n && i / s == l / s; ++i)
                    t[l / s].push_back(a[i]);
                sort(all(t[l / s]));
            }
            else
            {
                t[l / s].clear();
                for (int i = max(l / s * s, 1); i <= n && i / s == l / s; ++i)
                    a[i] = min(a[i] + ave[l / s], INF);
                ave[l / s] = 0;
                for (int i = l; i <= n && i / s == l / s; ++i)
                    a[i] = min(a[i] + x, INF);
                for (int i = max(l / s * s, 1); i <= n && i / s == l / s; ++i)
                    t[l / s].push_back(a[i]);
                t[r / s].clear();
                for (int i = max(r / s * s, 1); i <= n && i / s == r / s; ++i)
                    a[i] = min(a[i] + ave[r / s], INF);
                ave[r / s] = 0;
                for (int i = r; i >= 1 && i / s == r / s; --i)
                    a[i] = min(a[i] + x, INF);
                for (int i = max(r / s * s, 1); i <= n && i / s == r / s; ++i)
                    t[r / s].push_back(a[i]);
                sort(all(t[l / s]));
                sort(all(t[r / s]));
            }
        }
        else
        {
            int y;
            y = ka();
            int ul = -1;
            for (int i = 1 / s; i <= n / s; ++i)
            {
                if (binary_search(all(t[i]), y - ave[i]))
                {
                    ul = i;
                    break;
                }
            }
            if (ul == -1)
            {
                printf("-1\n");
                continue;
            }
            int ur;
            for (int i = n / s; i >= 1 / s; --i)
            {
                if (binary_search(all(t[i]), y - ave[i]))
                {
                    ur = i;
                    break;
                }
            }
            int l;
            for (int i = max(1, ul * s); ; ++i)
            {
                if (a[i] + ave[ul] == y)
                {
                    l = i;
                    break;
                }
            }
            int r;
            for (int i = min(n, (ur + 1) * s - 1); ; --i)
            {
                if (a[i] + ave[ur] == y)
                {
                    r = i;
                    break;
                }
            }
            printf("%d\n", r - l);
        }
    }
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
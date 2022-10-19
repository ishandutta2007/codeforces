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
const int N = 100005;

bool p[N];
bool c[N];
void solv()
{
    int n;
    scanf("%d", &n);
    int s = sqrt(n);

    for (int i = 2; i <= n; ++i)
        p[i] = true;
    for (int i = 2; i <= n; ++i)
    {
        if (!p[i])
            continue;
        for (int j = i + i; j <= n; j += i)
            p[j] = false;
    }
    int vp = -1;
    for (int i = n; i >= 1; --i)
    {
        if (p[i])
        {
            vp = i;
            break;
        }
    }

    int v0 = -1;
    vector<int> v;
    vector<int> u;
    for (int i = 1; i <= n; ++i)
    {
        if (!p[i])
            continue;
        u.push_back(i);
        printf("B %d\n", i);
        fflush(stdout);
        int q;
        scanf("%d", &q);
        int qq = 0;
        for (int j = i; j <= n; j += i)
        {
            if (!c[j])
            {
                ++qq;
                c[j] = true;
            }
        }
        if (q != qq)
        {
            v.push_back(i);
        }
        if (v0 == -1)
        {
            if (sz(u) == s || i == vp)
            {
                printf("A 1\n");
                fflush(stdout);
                int q;
                scanf("%d", &q);
                int qq = 0;
                for (int j = 1; j <= n; ++j)
                {
                    if (!c[j])
                        ++qq;
                }
                if (q != qq)
                {
                    for (int i = 0; i < sz(u); ++i)
                    {
                        printf("A %d\n", u[i]);
                        fflush(stdout);
                        int q;
                        scanf("%d", &q);
                        if (q)
                        {
                            v0 = u[i];
                            break;
                        }
                    }
                }
                u.clear();
            }
        }
    }
    if (v0 != -1)
        v.push_back(v0);

    int ans = 1;
    for (int i = 0; i < sz(v); ++i)
    {
        int q = 1;
        while (1)
        {
            int x = 1;
            for (int j = 0; j < q + 1; ++j)
            {
                if (x * 1LL * v[i] > n)
                {
                    x = n + 1;
                    break;
                }
                x *= v[i];
            }
            if (x > n)
                break;
            printf("A %d\n", x);
            fflush(stdout);
            int qq;
            scanf("%d", &qq);
            if (!qq)
                break;
            ++q;
        }
        for (int j = 0; j < q; ++j)
            ans *= v[i];
    }
    printf("C %d\n", ans);
    fflush(stdout);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
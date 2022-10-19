#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

void por()
{
    int n;
    scanf("%d", &n);
    for (int x = 1; x < (1 << n); ++x)
    {
        vector<int> v;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                v.push_back(i + 1);
        }
        vector<int> p(v.size());
        p[0] = v[0];
        for (int i = 1; i < v.size(); ++i)
            p[i] = p[i - 1] ^ v[i];
        bool z = true;
        for (int i = 1; i < v.size(); ++i)
        {
            if (p[i] <= p[i - 1])
            {
                z = false;
                break;
            }
        }
        if (!z)
            continue;
        for (int i = 0; i < v.size(); ++i)
            printf("%d ", v[i]);
        printf("\n");
        for (int i = 0; i < v.size(); ++i)
            printf("%d ", p[i]);
        printf("\n");
        printf("\n");
    }
}

void solv()
{
    int d, M;
    scanf("%d%d", &d, &M);
    int q = 1;
    int qq = 0;
    int ans = 1;
    while (1)
    {
        if (qq + q < d)
        {
            ans = (ans * 1LL * (q + 1)) % M;
            qq += q;
            q *= 2;
        }
        else
        {
            ans = (ans * 1LL * (d - qq + 1)) % M;
            break;
        }
    }
    ans = (ans - 1 + M) % M;
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
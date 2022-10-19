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
const int N = 200005, M = 998244353;

int n, k;
int a[N];
int b[N];

int u[N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= k; ++i)
        scanf("%d", &b[i]);

    set<int> s;
    for (int i = 1; i <= n; ++i)
    {
        s.insert(i);
        u[a[i]] = i;
    }

    set<int> ss;
    for (int i = 1; i <= k; ++i)
        ss.insert(b[i]);

    int ans = 1;
    for (int i = 1; i <= k; ++i)
    {
        int x = u[b[i]];

        auto it = s.find(x);
        auto itl = it;
        if (it == s.begin())
            itl = s.end();
        else
        {
            --itl;
            if (ss.find(a[*itl]) != ss.end())
                itl = s.end();
        }
        auto itr = it;
        if (it == (--s.end()))
            itr = s.end();
        else
        {
            ++itr;
            if (ss.find(a[*itr]) != ss.end())
                itr = s.end();
        }

        if (itl == s.end() && itr == s.end())
        {
            printf("0\n");
            return;
        }
        if (itl == s.end())
        {
            s.erase(itr);
        }
        else if (itr == s.end())
        {
            s.erase(itl);
        }
        else
        {
            s.erase(itl);
            ans = (ans * 2) % M;
        }
        ss.erase(a[x]);
    }
    printf("%d\n", ans);
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
        solv();
    return 0;
}
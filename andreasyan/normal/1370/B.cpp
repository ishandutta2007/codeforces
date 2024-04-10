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
    vector<int> v[2];
    for (int i = 1; i <= n * 2; ++i)
    {
        int x;
        scanf("%d", &x);
        v[x % 2].push_back(i);
    }
    if (v[1].size() % 2 == 0)
    {
        if (!v[0].empty())
        {
            for (int i = 0; i < sz(v[0]) - 2; i += 2)
                printf("%d %d\n", v[0][i], v[0][i + 1]);
            for (int i = 0; i < sz(v[1]); i += 2)
                printf("%d %d\n", v[1][i], v[1][i + 1]);
        }
        else
        {
            for (int i = 0; i < sz(v[1]) - 2; i += 2)
                printf("%d %d\n", v[1][i], v[1][i + 1]);
        }
    }
    else
    {
        for (int i = 0; i < sz(v[0]) - 1; i += 2)
            printf("%d %d\n", v[0][i], v[0][i + 1]);
        for (int i = 0; i < sz(v[1]) - 1; i += 2)
            printf("%d %d\n", v[1][i], v[1][i + 1]);
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
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
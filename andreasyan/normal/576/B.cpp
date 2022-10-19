#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, T = 86400, INF = 1000000009;

int n;
int p[N];
bool c[N];

void solv()
{
    vector<vector<int> > vv;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;
        vector<int> v;
        int x = i;
        while (1)
        {
            v.push_back(x);
            c[x] = true;
            x = p[x];
            if (c[x])
                break;
        }
        vv.push_back(v);
    }
    for (int i = 0; i < vv.size(); ++i)
    {
        if (vv[i].size() == 1)
        {
            printf("YES\n");
            for (int j = 1; j <= n; ++j)
            {
                if (j == vv[i][0])
                    continue;
                printf("%d %d\n", j, vv[i][0]);
            }
            return;
        }
    }
    for (int i = 0; i < vv.size(); ++i)
    {
        if (vv[i].size() % 2 == 1)
        {
            printf("NO\n");
            return;
        }
    }
    for (int i = 0; i < vv.size(); ++i)
    {
        if (vv[i].size() == 2)
        {
            printf("YES\n");
            printf("%d %d\n", vv[i][0], vv[i][1]);
            for (int j = 0; j < vv.size(); ++j)
            {
                if (i == j)
                    continue;
                for (int k = 0; k < vv[j].size(); ++k)
                {
                    printf("%d %d\n", vv[i][(k % 2)], vv[j][k]);
                }
            }
            return;
        }
    }
    printf("NO\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i]);
    solv();
    return 0;
}
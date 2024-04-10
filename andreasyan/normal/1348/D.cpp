#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);

void solv()
{
    int n;
    scanf("%d", &n);
    for (int m = 1; ; ++m)
    {
        vector<int> ans;
        int nn = n;
        nn -= (m + 1);
        int q = 1;
        for (int i = m; i >= 1; --i)
        {
            if (nn >= q * 1LL * i)
            {
                ans.push_back(q);
            }
            else
            {
                ans.push_back(nn / i);
            }
            nn -= (ans.back() * 1LL * i);
            q += ans.back();
        }
        if (nn == 0)
        {
            printf("%d\n", ans.size());
            for (int i = 0; i < ans.size(); ++i)
                printf("%d ", ans[i]);
            printf("\n");
            return;
        }
    }
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
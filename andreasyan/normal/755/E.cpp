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
    int n, k;
    scanf("%d%d", &n, &k);
    if (k > 3 || k == 1)
    {
        printf("-1\n");
        return;
    }
    vector<pair<int, int> > ans;
    if (k == 2)
    {
        if (n <= 4)
        {
            printf("-1\n");
            return;
        }
        for (int i = 1; i < n; ++i)
            ans.push_back(m_p(i, i + 1));
    }
    else
    {
        if (n <= 3)
        {
            printf("-1\n");
            return;
        }
        ans.push_back(m_p(1, 2));
        ans.push_back(m_p(2, 3));
        ans.push_back(m_p(3, 4));
        for (int i = 5; i <= n; ++i)
        {
            ans.push_back(m_p(i, 3));
            ans.push_back(m_p(i, 4));
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
    {
        printf("%d %d\n", ans[i].fi, ans[i].se);
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
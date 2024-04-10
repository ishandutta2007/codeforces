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

vector<pair<int, int> > ans;
void ave(int x, int y)
{
    ans.push_back(m_p(x, y));
}

void solv()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == 1 && j == 1)
                continue;
            ave(i, j);
        }
    }
    int x = 2, y = 2;
    for (int ii = 0; ii < n; ++ii)
    {
        for (int i = x; i < x + 3; ++i)
        {
            for (int j = y; j < y + 3; ++j)
            {
                if (i == x + 1 && j == y + 1)
                    continue;
                if (i == x && j == y)
                    continue;
                ave(i, j);
            }
        }
        x += 2;
        y += 2;
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d\n", ans[i].fi, ans[i].se);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
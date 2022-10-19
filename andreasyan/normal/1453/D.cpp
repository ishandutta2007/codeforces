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

ll k;

double clc(vector<int> v)
{
    double ans = 0;
    double anss[10] = {};
    for (int ii = 0; ii < 1000; ++ii)
    {
        int x = 0;
        int u = 0;
        while (x < v.size())
        {
            anss[x]++;
            ans += 1;
            if (rnf() % 2 == 0)
            {
                x = u;
            }
            else
            {
                ++x;
                if (x < v.size())
                {
                    if (v[x] == 1)
                        u = x;
                }
            }
        }
    }

    for (int i = 0; i < v.size(); ++i)
    {
        anss[i] /= 1000;
        cout << anss[i] << ' ';
    }
    cout << endl;

    ans /= 1000;
    return ans;
}

void solv()
{
    scanf("%lld", &k);

    if (k % 2 == 1)
    {
        printf("-1\n");
        return;
    }

    k /= 2;

    vector<int> ans;
    for (int i = 59; i >= 1; --i)
    {
        while ((1LL << i) - 1 <= k)
        {
            k -= ((1LL << i) - 1);
            ans.push_back(1);
            for (int j = 1; j < i; ++j)
                ans.push_back(0);
        }
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    printf("\n");

    //cout << clc(ans) << endl;
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
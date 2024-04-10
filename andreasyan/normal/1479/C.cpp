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
const int N = 44, M = 998244353;

int L, R;

int n;
vector<pair<pair<int, int>, int> > ans;
ll l[N], r[N];

void solv()
{
    scanf("%d%d", &L, &R);

    n = 32;
    l[n] = 0;
    r[n] = 0;
    for (int i = n - 1; i >= n - 20; --i)
    {
        for (int j = n; j > i; --j)
        {
            ans.push_back(m_p(m_p(i, j), r[j] - l[j] + 1));
        }
        l[i] = 1;
        r[i] = (1 << (n - i - 1));
    }
    for (int i = 2; i < n - 20; ++i)
    {
        ans.push_back(m_p(m_p(i, n), 1));
        l[i] = r[i] = 1;
    }

    int j = 2;
    for (int i = n - 20; i <= n; ++i)
    {
        if (L > R)
            break;
        if (L == R)
        {
            ans.push_back(m_p(m_p(1, n), R));
            break;
        }
        if (R - L + 1 >= r[i] - l[i] + 1)
        {
            if (R != r[i])
            {
                ans.push_back(m_p(m_p(1, i), R - r[i]));
                R = R - (r[i] - l[i] + 1);
            }
            else
            {
                ans.push_back(m_p(m_p(1, j++), R - 1));
                R = R - 1;
            }
        }
    }

    printf("YES\n");
    printf("%d %d\n", n, sz(ans));
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d %d\n", ans[i].fi.fi, ans[i].fi.se, ans[i].se);
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
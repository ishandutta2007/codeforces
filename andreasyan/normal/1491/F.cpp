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
const int N = 2003;

int qry(const vector<int>& l, const vector<int>& r)
{
    if (l.empty() || r.empty())
        return 0;
    printf("? %d %d\n", sz(l), sz(r));
    for (int i = 0; i < sz(l); ++i)
    {
        printf("%d ", l[i]);
    }
    printf("\n");
    for (int i = 0; i < sz(r); ++i)
    {
        printf("%d ", r[i]);
    }
    printf("\n");
    fflush(stdout);

    int ans;
    scanf("%d", &ans);
    return ans;
}

void solv()
{
    int n;
    scanf("%d", &n);

    vector<int> l, r;

    int u = -1;
    int uq;
    for (int i = 1; i <= n; ++i)
    {
        l.clear();
        r.clear();
        l.push_back(i);
        for (int j = i + 1; j <= n; ++j)
            r.push_back(j);

        if (uq = qry(l, r))
        {
            u = i;
            break;
        }
    }
    assert(u != -1);

    vector<int> ans;
    {
        int l0 = 1, r0 = u - 1;
        int uu = -1;
        while (l0 <= r0)
        {
            int m = (l0 + r0) / 2;
            l.clear();
            r.clear();
            r.push_back(u);
            for (int i = 1; i <= m; ++i)
                l.push_back(i);
            if (qry(l, r))
            {
                uu = m;
                r0 = m - 1;
            }
            else
                l0 = m + 1;
        }
        for (int i = 1; i < u; ++i)
        {
            if (i == uu)
                continue;
            ans.push_back(i);
        }
    }

    vector<int> save1;
    for (int i = u + 1; i <= n; ++i)
    {
        if (i < n)
        {
            l.clear();
            r.clear();
            l.push_back(u);
            r.push_back(i);
            int qq = qry(l, r);
            if (!qq)
                ans.push_back(i);
            save1.push_back(qq);
        }
        else
        {
            int s = 0;
            for (int i = 0; i < save1.size(); ++i)
                s += save1[i];
            if (s == uq)
                ans.push_back(i);
        }
    }

    printf("! %d ", sz(ans));
    for (int i = 0; i < sz(ans); ++i)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    fflush(stdout);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}
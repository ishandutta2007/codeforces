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
const int N = 500005, L = 22;

int n;
int a[N];

int uu[N], u[N];

int z;
int t[N * L];
int ul[N * L], ur[N * L];

int ubd(int tl, int tr, int x, int pos)
{
    int ypos = ++z;
    t[ypos] = t[pos];
    ul[ypos] = ul[pos];
    ur[ypos] = ur[pos];
    ++t[ypos];
    if (tl == tr)
    {
        return ypos;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ul[ypos] = ubd(tl, m, x, ul[pos]);
    else
        ur[ypos] = ubd(m + 1, tr, x, ur[pos]);
    return ypos;
}

int qry(int tl, int tr, int l, int r, int posr, int posl)
{
    if (tl == l && tr == r)
    {
        if (t[posr] - t[posl] == 0)
            return -1;
    }
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, ul[posr], ul[posl]);
    if (l > m)
        return qry(m + 1, tr, l, r, ur[posr], ur[posl]);
    int ansr = qry(m + 1, tr, m + 1, r, ur[posr], ur[posl]);
    if (ansr != -1)
        return ansr;
    return qry(tl, m, l, m, ul[posr], ul[posl]);
}

int root[N];

int dp[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    /*int xx;
    while (scanf("%d", &xx) != EOF)
    {
        a[++n] = xx;
    }*/
    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(a[i]);
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; ++i)
    {
        a[i] = lower_bound(all(v), a[i]) - v.begin();
    }
    for (int i = 0; i < v.size(); ++i)
        uu[i] = -1;
    for (int i = 1; i <= n; ++i)
    {
        u[i] = uu[a[i]];
        uu[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (u[i] != -1)
            root[i] = ubd(1, n, u[i], root[i - 1]);
        else
            root[i] = root[i - 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1];
        if (u[i] != -1 && u[i] != i - 1)
        {
            int x = qry(1, n, 1, u[i], root[i - 1], root[u[i]]);
            if (x != -1)
            {
                dp[i] = max(dp[i], dp[x - 1] + 1);
            }
        }
        int x = i;
        for (int j = 0; j < 3; ++j)
        {
            x = u[x];
            if (x == -1)
                break;
        }
        if (x != -1)
            dp[i] = max(dp[i], dp[x - 1] + 1);
    }
    int maxi;
    vector<int> ans;
    for (int i = 0; i <= n; ++i)
    {
        if (dp[i] == dp[n])
        {
            maxi = i;
            while (i)
            {
                if (dp[i] == dp[i - 1])
                {
                    --i;
                    continue;
                }
                if (u[i] != -1 && u[i] != i - 1)
                {
                    int x = qry(1, n, 1, u[i], root[i - 1], root[u[i]]);
                    if (x != -1)
                    {
                        if (dp[i] == dp[x - 1] + 1)
                        {
                            ans.push_back(v[a[i]]);
                            ans.push_back(v[a[x]]);
                            ans.push_back(v[a[i]]);
                            ans.push_back(v[a[x]]);
                            i = x - 1;
                            continue;
                        }
                    }
                }
                int x = i;
                for (int j = 0; j < 3; ++j)
                {
                    x = u[x];
                    if (x == -1)
                        break;
                }
                if (x != -1)
                {
                    if (dp[i] == dp[x - 1] + 1)
                    {
                        ans.push_back(v[a[i]]);
                        ans.push_back(v[a[i]]);
                        ans.push_back(v[a[i]]);
                        ans.push_back(v[a[i]]);
                        i = x - 1;
                        continue;
                    }
                }
                assert(false);
            }
            reverse(ans.begin(), ans.end());
            break;
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
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
const int N = 102;

int n, m;
int s[N], h[N];
int rs[N];

int a[N];

int minu[N][N];

bool dp[4][N];
int p[4][N];

void pro(int u, int k, vector<pair<int, int> > v)
{
    reverse(all(v));
    v.push_back(m_p(-1, -1));
    reverse(all(v));
    int uu = 0;
    if (k == 1)
        uu = 1;
    else
        uu = -1;
    for (int i = 0; i < v.size(); ++i)
    {
        if (i == 0)
        {
            dp[k][i] = true;
            continue;
        }
        for (int j = 0; j < i; ++j)
        {
            if (j == 0)
            {
                if (k % 2 == 0)
                {
                    if (v[i].se + minu[v[i].fi][u - uu] >= 0)
                    {
                        dp[k][i] = true;
                        p[k][i] = j;
                        break;
                    }
                }
                else
                {
                    if (v[i].se + minu[v[i].fi][u] >= 0)
                    {
                        dp[k][i] = true;
                        p[k][i] = j;
                        break;
                    }
                }
            }
            else
            {
                if (dp[k][j] && v[i].se + minu[v[i].fi][v[j].fi - uu] >= 0)
                {
                    dp[k][i] = true;
                    p[k][i] = j;
                    break;
                }
            }
        }
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &s[i], &h[i]);
        rs[s[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        minu[i][i] = min(a[i], 0);
        int p = a[i];
        for (int j = i + 1; j <= n; ++j)
        {
            p += a[j];
            minu[i][j] = min(minu[i][j - 1], p);
        }
        p = a[i];
        for (int j = i - 1; j >= 1; --j)
        {
            p += a[j];
            minu[i][j] = min(minu[i][j + 1], p);
        }
    }
    for (int u = 1; u <= n; ++u)
    {
        vector<pair<int, int> > vl, vr;
        for (int i = 1; i <= m; ++i)
        {
            if (s[i] <= u)
                vl.push_back(m_p(s[i], h[i]));
            else
                vr.push_back(m_p(s[i], h[i]));
        }
        sort(all(vl));
        reverse(all(vl));
        sort(all(vr));
        memset(dp, false, sizeof dp);
        pro(u, 0, vl);
        pro(u, 1, vl);
        pro(u, 2, vr);
        pro(u, 3, vr);
        if (dp[0][vl.size()] && dp[3][vr.size()] && !vr.empty())
        {
            int i = vr.size();
            vector<int> ansr;
            while (i)
            {
                ansr.push_back(rs[vr[i - 1].fi]);
                i = p[3][i];
            }
            vector<int> ansl;
            i = vl.size();
            while (i)
            {
                ansl.push_back(rs[vl[i - 1].fi]);
                i = p[0][i];
            }
            vector<int> ans;
            set<int> s;
            reverse(all(ansr));
            for (int i = 0; i < ansr.size(); ++i)
                ans.push_back(ansr[i]);
            reverse(all(ansl));
            for (int i = 0; i < ansl.size(); ++i)
                ans.push_back(ansl[i]);
            for (int i = 0; i < ans.size(); ++i)
                s.insert(ans[i]);
            for (int i = 1; i <= m; ++i)
            {
                if (s.find(i) == s.end())
                    ans.push_back(i);
            }
            printf("%d\n", u);
            for (int i = 0; i < ans.size(); ++i)
                printf("%d ", ans[i]);
            printf("\n");
            return;
        }
        if (dp[1][vl.size()] && dp[2][vr.size()] && !vl.empty())
        {
            vector<int> ansl;
            int i = vl.size();
            while (i)
            {
                ansl.push_back(rs[vl[i - 1].fi]);
                i = p[1][i];
            }
            i = vr.size();
            vector<int> ansr;
            while (i)
            {
                ansr.push_back(rs[vr[i - 1].fi]);
                i = p[2][i];
            }
            vector<int> ans;
            set<int> s;
            reverse(all(ansl));
            for (int i = 0; i < ansl.size(); ++i)
                ans.push_back(ansl[i]);
            reverse(all(ansr));
            for (int i = 0; i < ansr.size(); ++i)
                ans.push_back(ansr[i]);
            for (int i = 0; i < ans.size(); ++i)
                s.insert(ans[i]);
            for (int i = 1; i <= m; ++i)
            {
                if (s.find(i) == s.end())
                    ans.push_back(i);
            }
            printf("%d\n", u);
            for (int i = 0; i < ans.size(); ++i)
                printf("%d ", ans[i]);
            printf("\n");
            return;
        }
    }
    printf("-1\n");
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
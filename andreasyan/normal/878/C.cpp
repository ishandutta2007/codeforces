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
const int N = 50004, K = 12;

int n, k;
int a[N][K];

int p[N], u[N];

bool so(int x, int y)
{
    return a[x][1] < a[y][1];
}

int minu[N][K], maxu[N][K];
int q[N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
            cin >> a[i][j];
    }

    for (int i = 1; i <= n; ++i)
        p[i] = i;
    sort(p + 1, p + n + 1, so);
    for (int i = 1; i <= n; ++i)
        u[p[i]] = i;

    set<pair<int, int> > s;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
            minu[u[i]][j] = maxu[u[i]][j] = a[i][j];
        q[u[i]] = 1;

        if (s.empty())
        {
            s.insert(m_p(u[i], u[i]));
        }
        else
        {
            auto it = s.lower_bound(m_p(u[i], 0));
            if (it == s.begin())
                s.insert(m_p(u[i], u[i]));
            else
            {
                --it;
                if (it->se < u[i])
                    s.insert(m_p(u[i], u[i]));
                else
                {
                    for (int j = 1; j <= k; ++j)
                    {
                        minu[it->fi][j] = min(minu[it->fi][j], a[i][j]);
                        maxu[it->fi][j] = max(maxu[it->fi][j], a[i][j]);
                    }
                    ++q[it->fi];
                }
            }
        }

        while (1)
        {
            auto it = s.lower_bound(m_p(u[i], N));
            if (it == s.end())
                break;

            auto jt = it;
            --jt;

            bool z = false;
            for (int j = 1; j <= k; ++j)
            {
                if (maxu[jt->fi][j] > minu[it->fi][j])
                {
                    z = true;
                    break;
                }
            }

            if (z)
            {
                for (int j = 1; j <= k; ++j)
                {
                    minu[jt->fi][j] = min(minu[jt->fi][j], minu[it->fi][j]);
                    maxu[jt->fi][j] = max(maxu[jt->fi][j], maxu[it->fi][j]);
                }
                q[jt->fi] += q[it->fi];
                pair<int, int> h = m_p(jt->fi, it->se);
                s.erase(it);
                s.erase(jt);
                s.insert(h);
            }
            else
                break;
        }

        while (1)
        {
            auto it = s.lower_bound(m_p(u[i], N));
            --it;
            if (it == s.begin())
                break;

            auto jt = it;
            --jt;

            bool z = false;
            for (int j = 1; j <= k; ++j)
            {
                if (maxu[jt->fi][j] > minu[it->fi][j])
                {
                    z = true;
                    break;
                }
            }

            if (z)
            {
                for (int j = 1; j <= k; ++j)
                {
                    minu[jt->fi][j] = min(minu[jt->fi][j], minu[it->fi][j]);
                    maxu[jt->fi][j] = max(maxu[jt->fi][j], maxu[it->fi][j]);
                }
                q[jt->fi] += q[it->fi];
                pair<int, int> h = m_p(jt->fi, it->se);
                s.erase(it);
                s.erase(jt);
                s.insert(h);
            }
            else
                break;
        }

        cout << q[(--s.end())->fi] << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}
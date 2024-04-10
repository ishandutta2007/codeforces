#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 50004;

int n;
int t[N], s[N], p[N];
int x;

vector<pair<int, int> > vt;

long long f[N];

long long stg(int px)
{
    p[x] = px;
    long long tt = 0;
    priority_queue<pair<int, pair<int, int> > > q;
    for (int ii = 0; ii < n; ++ii)
    {
        int i = vt[ii].second;
        while (1)
        {
            if (q.empty())
                break;
            pair<int, pair<int, int> > u = q.top();
            q.pop();
            if ((tt + u.second.second) <= t[i])
            {
                tt += u.second.second;
                f[u.second.first] = tt;
            }
            else
            {
                u.second.second -= (t[i] - tt);
                q.push(u);
                break;
            }
        }
        tt = t[i];
        q.push(m_p(p[i], m_p(i, s[i])));
    }
    while (!q.empty())
    {
        pair<int, pair<int, int> > u = q.top();
        q.pop();
        tt += u.second.second;
        f[u.second.first] = tt;
    }
    return f[x];
}

long long fx;

void solv()
{
    scanf("%d", &n);
    vector<int> pp;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d", &t[i], &s[i], &p[i]);
        vt.push_back(m_p(t[i], i));
        if (p[i] == -1)
            x = i;
        else
            pp.push_back(p[i]);
    }
    scanf("%lld", &fx);
    if (pp.empty())
    {
        printf("1\n");
        return;
    }
    sort(vt.begin(), vt.end());
    sort(pp.begin(), pp.end());
    vector<int> v;
    if (pp[0] - 1 >= 1)
        v.push_back(pp[0] - 1);
    for (int i = 0; i < pp.size(); ++i)
    {
        if (i == pp.size() - 1 || pp[i] + 1 != pp[i + 1])
            v.push_back(pp[i] + 1);
    }
    int l = 0, r = v.size() - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        long long u = stg(v[m]);
        if (u == fx)
        {
            printf("%d\n", v[m]);
            for (int i = 1; i <= n; ++i)
                printf("%lld ", f[i]);
            printf("\n");
            return;
        }
        if (u < fx)
        {
            r = m - 1;
        }
        else
            l = m + 1;
    }
    printf("Well, we are not doing that.\n");
}

int main()
{
    //#ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //#endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
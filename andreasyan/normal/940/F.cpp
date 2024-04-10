#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;
int sn;
struct ban
{
    int i;
    int l, r, t;
    ban(){}
    ban(int i, int l, int r, int t)
    {
        this->i = i;
        this->l = l;
        this->r = r;
        this->t = t;
    }
};
bool operator<(const ban& a, const ban& b)
{
    if (a.l / sn < b.l / sn)
        return true;
    if (a.l / sn > b.l / sn)
        return false;
    if (a.r / sn < b.r / sn)
        return true;
    if (a.r / sn > b.r / sn)
        return false;
    return a.t < b.t;
}


int n, m;
int a[N];
int ca[N];

vector<ban> q;
vector<pair<int, int> > u;
vector<int> uu;

int z;
map<int, int> mp;

int qa[N * 2];
int qq[N * 2];

void ubda(int x)
{
    qq[qa[x]]--;
    qa[x]++;
    qq[qa[x]]++;
}

void ubdh(int x)
{
    qq[qa[x]]--;
    qa[x]--;
    qq[qa[x]]++;
}

int ans[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        if (mp.find(a[i]) == mp.end())
            mp[a[i]] = ++z;
        a[i] = mp[a[i]];
        ca[i] = a[i];
    }
    for (int i = 0; i < m; ++i)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            q.push_back(ban(i, l, r, u.size()));
        }
        else
        {
            int j, x;
            scanf("%d%d", &j, &x);
            if (mp.find(x) == mp.end())
                mp[x] = ++z;
            x = mp[x];
            u.push_back(m_p(j, x));
        }
    }
    for (int i = 0; i < u.size(); ++i)
    {
        uu.push_back(ca[u[i].first]);
        ca[u[i].first] = u[i].second;
    }
    sn = pow(n, 1.0 * 2 / 3);
    sort(q.begin(), q.end());
    qq[0] = 1000000000;
    int l = 1, r = 0, t = 0;
    for (int i = 0; i < q.size(); ++i)
    {
        int ll = q[i].l, rr = q[i].r, tt = q[i].t;
        while (r < rr)
        {
            ++r;
            ubda(a[r]);
        }
        while (l > ll)
        {
            --l;
            ubda(a[l]);
        }
        while (t < tt)
        {
            ++t;
            if (l <= u[t - 1].first && u[t - 1].first <= r)
            {
                ubdh(a[u[t - 1].first]);
            }
            a[u[t - 1].first] = u[t - 1].second;
            if (l <= u[t - 1].first && u[t - 1].first <= r)
            {
                ubda(a[u[t - 1].first]);
            }
        }
        while (r > rr)
        {
            ubdh(a[r]);
            --r;
        }
        while (l < ll)
        {
            ubdh(a[l]);
            ++l;
        }
        while (t > tt)
        {
            if (l <= u[t - 1].first && u[t - 1].first <= r)
            {
                ubdh(a[u[t - 1].first]);
            }
            a[u[t - 1].first] = uu[t - 1];
            if (l <= u[t - 1].first && u[t - 1].first <= r)
            {
                ubda(a[u[t - 1].first]);
            }
            --t;
        }
        for (int j = 0; ; ++j)
        {
            if (!qq[j])
            {
                ans[q[i].i] = j;
                break;
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        if (ans[i])
            printf("%d\n", ans[i]);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 400005;

int n;
int l[N], r[N];

int z;
map<int, int> mp;
vector<int> v;

vector<pair<int, int> > vv[N];

int t[N * 4];

void ubd(int x, int y)
{
    while (x <= z)
    {
        t[x] += y;
        x += (x & (-x));
    }
}

int qry(int l, int r)
{
    int ans = 0;
    while (r)
    {
        ans += t[r];
        r -= (r & (-r));
    }
    --l;
    while (l)
    {
        ans -= t[l];
        l -= (l & (-l));
    }
    return ans;
}

int ans[N];

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &l[i], &r[i]);
        r[i] += l[i];
        v.push_back(l[i]);
        v.push_back(r[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n * 2; ++i)
    {
        if (!i || v[i] != v[i - 1])
            mp[v[i]] = ++z;
    }
    int qq;
    scanf("%d", &qq);
    for (int i = 1; i <= qq; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        vv[x].push_back(m_p(y, i));
    }
    set<pair<int, int> > s;
    for (int i = n; i >= 1; --i)
    {
        int rr = r[i];
        while (!s.empty())
        {
            if (s.begin()->first <= rr)
            {
                if (s.size() > 1)
                    ubd(mp[s.begin()->second], -((++s.begin())->first - s.begin()->second));
                rr = max(rr, s.begin()->second);
                s.erase(s.begin());
            }
            else
                break;
        }
        if (!s.empty())
        {
            ubd(mp[rr], s.begin()->first - rr);
        }
        s.insert(m_p(l[i], rr));
        for (int j = 0; j < vv[i].size(); ++j)
        {
            ans[vv[i][j].second] = qry(mp[l[i]], mp[l[vv[i][j].first]]);
        }
    }
    for (int i = 1; i <= qq; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
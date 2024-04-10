#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int m;
pair<char, int> b[N];

int n;
vector<int> v;
map<int, int> mp;
int rmp[N];

struct ban
{
    int q;
    long long ans[5];
    ban()
    {
        q = 0;
        memset(ans, 0, sizeof ans);
    }
    ban(int x)
    {
        q = 1;
        memset(ans, 0, sizeof ans);
        ans[0] = x;
    }
};

ban t[N * 4];

ban mer(const ban& l, const ban& r)
{
    ban ans;
    ans = l;
    for (int i = 0; i < 5; ++i)
    {
        ans.ans[(l.q + i) % 5] += r.ans[i];
    }
    ans.q += r.q;
    return ans;
}

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        if (y > 0)
            t[pos] = ban(rmp[x]);
        else
            t[pos] = ban();
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        char ty[5];
        scanf(" %s", ty);
        int x = 0;
        if (ty[0] == 'a' || ty[0] == 'd')
        {
            scanf("%d", &x);
            v.push_back(x);
        }
        b[i] = m_p(ty[0], x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        if (!i || v[i] != v[i - 1])
        {
            mp[v[i]] = ++n;
            rmp[n] = v[i];
        }
    }
    for (int i = 0; i < m; ++i)
    {
        if (b[i].first == 'a')
            ubd(1, n, mp[b[i].second], 1, 1);
        else if (b[i].first == 'd')
            ubd(1, n, mp[b[i].second], -1, 1);
        else
            printf("%I64d\n", t[1].ans[2]);
    }
    return 0;
}
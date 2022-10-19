#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 10004;
struct ban
{
    int x;
    int l, r;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}

int n;
int x1[N], y1_[N], x2[N], y2[N];

int xn;
ban a[N];
int yn;
ban b[N];

queue<int> q[N];

pair<int, int> hat(pair<int, int> a, pair<int, int> b)
{
    if (a.second > b.second)
        swap(a, b);
    if (a.second < b.first)
        return m_p(0, -1);
    if (b.first <= a.first)
        return a;
    return m_p(b.first, a.second);
}

int t[N];
void ubd(int x, int y)
{
    while (x < N)
    {
        t[x] += y;
        x += (x & (-x));
    }
}
int qry(int l, int r)
{
    if (r < l)
        return 0;
    int ans = 0;
    while (r > 0)
    {
        ans += t[r];
        r -= (r & (-r));
    }
    --l;
    while (l > 0)
    {
        ans -= t[l];
        l -= (l & (-l));
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    int minx = N;
    int miny = N;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d%d", &x1[i], &y1_[i], &x2[i], &y2[i]);
        minx = min(minx, x1[i]);
        minx = min(minx, x2[i]);
        miny = min(miny, y1_[i]);
        miny = min(miny, y2[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        x1[i] = x1[i] - minx + 1;
        y1_[i] = y1_[i] - miny + 1;
        x2[i] = x2[i] - minx + 1;
        y2[i] = y2[i] - miny + 1;
    }
    for (int i = 0; i < n; ++i)
    {
        if (x1[i] == x2[i])
        {
            a[xn].x = x1[i];
            a[xn].l = min(y1_[i], y2[i]);
            a[xn].r = max(y1_[i], y2[i]);
            ++xn;
        }
        else
        {
            b[yn].x = y1_[i];
            b[yn].l = min(x1[i], x2[i]);
            b[yn].r = max(x1[i], x2[i]);
            ++yn;
        }
    }
    vector<int> v;
    for (int i = 0; i < yn; ++i)
        v.push_back(b[i].r);
    sort(v.begin(), v.end());
    sort(a, a + xn);
    long long ans = 0;
    for (int i = 0; i < xn; ++i)
    {
        for (int j = 0; j < yn; ++j)
        {
            if (b[j].l <= a[i].x && a[i].x <= b[j].r)
            {
                ubd(b[j].x, 1);
                q[b[j].r].push(b[j].x);
            }
        }
        int jj = 0;
        for (int j = i + 1; j < xn; ++j)
        {
            while (jj < v.size() && a[j].x > v[jj])
            {
                int ii = v[jj];
                while (!q[ii].empty())
                {
                    ubd(q[ii].front(), -1);
                    q[ii].pop();
                }
                ++jj;
            }
            pair<int, int> h = hat(m_p(a[i].l, a[i].r), m_p(a[j].l, a[j].r));
            int m = qry(h.first, h.second);
            ans += (m * (m - 1) / 2);
        }
        while (jj < v.size())
        {
            int ii = v[jj];
            while (!q[ii].empty())
            {
                ubd(q[ii].front(), -1);
                q[ii].pop();
            }
            ++jj;
        }
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct ban
{
    int x, y;
};
bool operator<(const ban& a, const ban& b)
{
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    return a.y < b.y;
}

int n;
ban a[N];

int q[N];
int t[N];
void ubd(int x, int y)
{
    q[x] += y;
    if (q[x] == 1 && y == 1)
    {
        while (x < N)
        {
            t[x]++;
            x += (x & (-x));
        }
    }
    if (q[x] == 0 && y == -1)
    {
        while (x < N)
        {
            t[x]--;
            x += (x & (-x));
        }
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

long long ans;
void solv(const vector<int>& v)
{
    long long nn = qry(1, N - 1);
    ans = ans + (nn * 1LL * (nn + 1)) / 2;
    nn = qry(1, v[0] - 1);
    ans = ans - (nn * 1LL * (nn + 1)) / 2;
    for (int i = 0; i < v.size() - 1; ++i)
    {
        nn = qry(v[i] + 1, v[i + 1] - 1);
        ans = ans - (nn * 1LL * (nn + 1)) / 2;
    }
    nn = qry(v.back() + 1, N - 1);
    ans = ans - (nn * 1LL * (nn + 1)) / 2;
    for (int i = 0; i < v.size(); ++i)
        ubd(v[i], -1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &a[i].x, &a[i].y);
        swap(a[i].x, a[i].y);
    }
    int z;
    map<int, int> mp;
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(a[i].x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        if (!i || v[i] != v[i - 1])
        {
            mp[v[i]] = ++z;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        a[i].x = mp[a[i].x];
    }
    z = 0;
    mp.clear();
    v.clear();
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(a[i].y);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        if (!i || v[i] != v[i - 1])
        {
            mp[v[i]] = ++z;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        a[i].y = mp[a[i].y];
    }
    // let's start
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        ubd(a[i].y, 1);
    }
    v.clear();
    for (int i = 1; i <= n; ++i)
    {
        if (i > 1 && a[i].x != a[i - 1].x)
        {
            solv(v);
            v.clear();
            v.push_back(a[i].y);
        }
        else
        {
            v.push_back(a[i].y);
        }
    }
    solv(v);
    cout << ans << endl;
    return 0;
}
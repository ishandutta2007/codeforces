#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2e6 + 9;
int p[maxn];
int sz[maxn];
int lst[maxn];
pii q[maxn];
int n;

int find_p(int i)
{
    if (p[i] != i)
        p[i] = find_p(p[i]);
    return p[i];
}

void merg(int i, int e)
{
    i = find_p(i);
    e = find_p(e);
    if (i == e)
        return;
    if (sz[i] < sz[e])
        swap(i, e);
    sz[i] += sz[e];
    p[e] = i;
    lst[i] = max(lst[i], lst[e]);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> n >> s;
    int c0 = 0, c1 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            c0++;
            c1 = 0;
        }
        else if (s[i] == '1')
        {
            c1++;
            c0 = 0;
        }
        else
        {
            c0++;
            c1++;
        }
        q[i] = mp(max(c0, c1), i);
    }
    sort(q, q + n);
    for (int i = 0; i < maxn; i++)
    {
        p[i] = i;
        sz[i] = 1;
        lst[i] = i;
    }
    int pt = 0;
    for (int j = 1; j <= n; j++)
    {
        while (pt < n && q[pt].ff < j)
        {
            merg(q[pt].ss, q[pt].ss + 1);
            pt++;
        }
        int ans = 0;
        for (int e = lst[find_p(0)]; e < n; e = lst[find_p(e + j)])
            ans++;
        cout << ans << " ";
    }
}
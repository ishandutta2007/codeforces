#include <bits/stdc++.h>
using namespace std;
const int N = 2003;

int n;
int a[N];

int z;
vector<int> v;
map<int, int> mp;

int qq;
int q[N];

int ave(int x)
{
    q[x]++;
    if (q[x] == 2)
        ++qq;
}
int han(int x)
{
    q[x]--;
    if (q[x] == 1)
        --qq;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        if (i == 0 || v[i] != v[i - 1])
            mp[v[i]] = ++z;
    }
    for (int i = 1; i <= n; ++i)
        a[i] = mp[a[i]];
    int ans = N;
    for (int i = 1; i <= n; ++i)
    {
        qq = 0;
        memset(q, 0, sizeof q);
        for (int j = 1; j <= n; ++j)
            ave(a[j]);
        if (qq == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        for (int j = i; j <= n; ++j)
        {
            han(a[j]);
            if (qq == 0)
            {
                ans = min(ans, (j - i + 1));
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
const long long M = 998244353;

int n;
vector<int> a, b;

long long f[N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * i) % M;
}

long long stg(vector<int> v)
{
    long long ans = 1;
    sort(v.begin(), v.end());
    int q = 1;
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] == v[i - 1])
            ++q;
        else
        {
            ans = (ans * f[q]) % M;
            q = 1;
        }
    }
    ans = (ans * f[q]) % M;
    return ans;
}

vector<int> v[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a.push_back(x);
        b.push_back(y);
    }
    pre();
    long long pans = (stg(a) + stg(b)) % M;
    for (int i = 0; i < n; ++i)
    {
        v[a[i]].push_back(b[i]);
    }
    long long mans = 1;
    int maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (v[i].empty())
            continue;
        sort(v[i].begin(), v[i].end());
        if (i > 1 && maxu > v[i][0])
        {
            mans = 0;
            break;
        }
        maxu = v[i].back();
        mans = (mans * stg(v[i])) % M;
    }
    cout << (f[n] - pans + mans + M) % M << endl;
    return 0;
}
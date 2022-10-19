#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;

int n;
pair<pair<int, int>, long long> b[N];
vector<pair<int, long long> > a[N];

long long ynt2(long long x)
{
    return (x * (x - 1));
}

long double ans;
long double t;
long long q[N];
void dfs(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        long long d = a[x][i].second;
        if (h == p)
            continue;
        dfs(h, x);
        ans += (d * ynt2(q[h]) * (n - q[h])) / t;
        ans += (d * ynt2(n - q[h]) * q[h]) / t;
        q[x] += q[h];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    cin >> n;
    for (int i = 1; i <= n - 1; ++i)
    {
        int x, y;
        long long z;
        cin >> x >> y >> z;
        b[i] = m_p(m_p(x, y), z);
        a[x].push_back(m_p(y, z));
        a[y].push_back(m_p(x, z));
    }
    t = (1LL * n * (n - 1) * (n - 2)) / 6;
    dfs(1, 1);
    int m;
    cin >> m;
    while (m--)
    {
        int i;
        long long z;
        cin >> i >> z;
        int x = b[i].first.first;
        int y = b[i].first.second;
        long long d = b[i].second - z;
        b[i].second = z;
        if (q[x] > q[y])
            swap(x, y);
        ans -= (d * ynt2(q[x]) * (n - q[x])) / t;
        ans -= (d * ynt2(n - q[x]) * q[x]) / t;
        cout << ans << endl;
    }
    return 0;
}
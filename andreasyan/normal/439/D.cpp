#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m;
int a[N], b[N];

vector<long long> v;
long long ga[N * 8];
long long gb[N * 8];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        v.push_back(a[i] - 1);
        v.push_back(a[i]);
        v.push_back(a[i] + 1);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
        v.push_back(b[i] - 1);
        v.push_back(b[i]);
        v.push_back(b[i] + 1);
    }
    sort(a, a + n);
    sort(b, b + m);
    sort(v.begin(), v.end());

    int j = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (i)
            ga[i] = ga[i - 1] + (j * (v[i] - v[i - 1]));
        while (j != n && a[j] < v[i])
        {
            ga[i] += (v[i] - a[j]);
            ++j;
        }
    }

    j = m - 1;
    for (int i = v.size() - 1; i >= 0; --i)
    {
        if (i != v.size())
            gb[i] = gb[i + 1] + ((m - 1 - j) * (v[i + 1] - v[i]));
        while (j >= 0 && b[j] > v[i])
        {
            gb[i] += (b[j] - v[i]);
            --j;
        }
    }

    long long ans = ga[0] + gb[0];
    for (int i = 1; i < v.size(); ++i)
        ans = min(ans, ga[i] + gb[i]);

    cout << ans << endl;
    return 0;
}
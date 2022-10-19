#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 503;

int n, k;
int a[N];

pair<int, int> qry(const vector<int>& v)
{
    cout << "? ";
    for (int i = 0; i < k; ++i)
        cout << v[i] << ' ';
    cout << endl;
    int x, y;
    cin >> x >> y;
    return m_p(x, y);
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        a[i] = -1;
    for (int ii = 1; ii <= n - k + 1; ++ii)
    {
        vector<int> v;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == -1)
            {
                v.push_back(i);
                if (v.size() == k)
                    break;
            }
        }
        pair<int, int> u = qry(v);
        a[u.first] = u.second;
    }
    vector<int> b;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != -1)
            b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == -1)
        {
            vector<int> v;
            for (int j = 1; j <= n; ++j)
            {
                if (j == i)
                    continue;
                if (a[j] == -1)
                    v.push_back(j);
                else if (a[j] == b[0])
                    v.push_back(j);
                else if (a[j] == b[1])
                    v.push_back(j);
            }
            pair<int, int> u = qry(v);
            if (u.second == b[1])
                ++ans;
        }
    }
    cout << "! " << ans << endl;
    return 0;
}
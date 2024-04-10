#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int pr[n];
    map<int, int> m;
    map<int, int> q;
    int ma = 0;
    int id;
    for (int i = 0; i < n; i++)
    {
        auto j = m.find(a[i] - 1);
        if (j == m.end())
        {
            m[a[i]] = 1;
        }
        else
        {
            int k = (*j).second;
            k++;
            m[a[i]] = k;
            pr[i] = q[a[i] - 1];
        }
        q[a[i]] = i;
        if (m[a[i]] > ma)
        {
            ma = m[a[i]];
            id = i;
        }
    }
    int ans[ma];
    for (int i = 0; i < ma; i++)
    {
        ans[i] = id + 1;
        id = pr[id];
    }
    cout << ma << endl;
    for (int i = ma - 1; i >= 0; i--)
        cout << ans[i] << " ";
}
#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
char a[N];

int q;
queue<int> z, m;
vector<int> v[N];

int main()
{
    cin >> a;
    n = strlen(a);
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '0')
        {
            if (m.empty())
            {
                v[++q].push_back(i);
                z.push(q);
            }
            else
            {
                v[m.front()].push_back(i);
                z.push(m.front());
                m.pop();
            }
        }
        else
        {
            if (z.empty())
            {
                cout << -1 << endl;
                return 0;
            }
            v[z.front()].push_back(i);
            m.push(z.front());
            z.pop();
        }
    }
    if (!m.empty())
    {
        cout << -1 << endl;
        return 0;
    }
    cout << q << endl;
    for (int i = 1; i <= q; ++i)
    {
        cout << v[i].size() << ' ';
        for (int j = 0; j < v[i].size(); ++j)
        {
            cout << v[i][j] + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, k;
vector<int> a[N];

int d[N], dd[N];

int c[N];
queue<int> q;

int main()
{
    cin >> n >> k;
    if (n == 1)
    {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        d[i] = a[i].size();
        if (d[i] == 1)
        {
            c[i] = 1;
            q.push(i);
        }
    }
    int z = 1;
    while (1)
    {
        ++z;
        if (q.size() == 1)
            break;
        set<int> s;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            int q0 = 0;
            for (int i = 0; i < a[x].size(); ++i)
            {
                int h = a[x][i];
                if (c[h] == 0)
                {
                    s.insert(h);
                    dd[h] ++;
                    q0++;
                }
            }
            if (q0 != 1)
            {
                cout << "No" << endl;
                return 0;
            }
        }
        for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
        {
            int x = *it;
            if (dd[x] < 3)
            {
                cout << "No" << endl;
                return 0;
            }
            c[x] = z;
            q.push(x);
            if (d[x] - dd[x] != 1 && q.size() > 1)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    int x = q.front();
    q.pop();
    if (d[x] - dd[x] == 0 && c[x] == k + 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
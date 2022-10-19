#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m;
int c[N];
vector<int> a[N], b[N];

int q[N];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++ i)
        cin >> c[i];
    for (int i = 0; i < m; ++ i)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        b[y].push_back(x);
    }
    queue<int> q0, q1;
    for (int i = 0; i < n; ++ i)
    {
        q[i] = a[i].size();
        if (!q[i])
        {
            if (c[i] == 0)
                q0.push(i);
            else
                q1.push(i);
        }
    }
    int ans = 0;
    while (1)
    {
        if (q0.empty() && q1.empty())
            break;
        else if (q0.empty())
        {
            ans ++;
            while (!q1.empty())
            {
                int x = q1.front();
                q1.pop();
                for (int i = 0; i < b[x].size(); ++ i)
                {
                    int p = b[x][i];
                    q[p] --;
                    if (q[p] == 0)
                    {
                        if (c[p] == 0)
                            q0.push(p);
                        else
                            q1.push(p);
                    }
                }
            }
        }
        else
        {
            while (!q0.empty())
            {
                int x = q0.front();
                q0.pop();
                for (int i = 0; i < b[x].size(); ++ i)
                {
                    int p = b[x][i];
                    q[p] --;
                    if (q[p] == 0)
                    {
                        if (c[p] == 0)
                            q0.push(p);
                        else
                            q1.push(p);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
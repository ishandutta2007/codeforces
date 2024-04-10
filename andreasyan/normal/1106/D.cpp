#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m;
vector<int> a[N];

bool c[N];
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    priority_queue<int> q;
    q.push(-1);
    while (!q.empty())
    {
        int x;
        do
        {
            if (q.empty())
            {
                cout << endl;
                return 0;
            }
            x = -q.top();
            q.pop();
        } while (c[x]);
        c[x] = true;
        cout << x << ' ';
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (!c[h])
                q.push(-h);
        }
    }
    return 0;
}
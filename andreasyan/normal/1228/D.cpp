#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m;
vector<int> a[N];

int k;
int c[N];

int main()
{
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        sort(a[i].begin(), a[i].end());
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            ++k;
            if (k == 4)
            {
                cout << -1 << endl;
                return 0;
            }
            for (int j = 1; j <= n; ++j)
            {
                if (a[i] == a[j])
                {
                    if (c[j])
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                    c[j] = k;
                }
            }
        }
    }
    if (k != 3)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << c[i] << ' ';
    }
    cout << endl;
    return 0;
}
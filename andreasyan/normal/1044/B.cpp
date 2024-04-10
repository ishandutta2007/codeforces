#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n;
vector<int> a[N];
vector<int> aa, bb;

bool c[N];

int y;
void dfs(int x, int p)
{
    if (c[x])
    {
        y = x;
        return;
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        a[i].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int k1, k2;
    aa.clear();
    bb.clear();
    cin >> k1;
    while (k1--)
    {
        int x;
        cin >> x;
        aa.push_back(x);
    }
    cin >> k2;
    while (k2--)
    {
        int x;
        cin >> x;
        bb.push_back(x);
    }

    for (int i = 1; i <= n; ++i)
        c[i] = false;
    for (int i = 0; i < aa.size(); ++i)
        c[aa[i]] = true;

    cout << "B " << bb[0] << endl;
    int x;
    cin >> x;
    if (c[x])
    {
        cout << "C " << x << endl;
        return;
    }
    dfs(x, 0);
    cout << "A " << y << endl;
    int yy;
    cin >> yy;
    for (int i = 0; i < bb.size(); ++i)
    {
        if (yy == bb[i])
        {
            cout << "C " << y << endl;
            return;
        }
    }
    cout << "C -1" << endl;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}
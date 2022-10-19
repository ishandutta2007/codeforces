#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}
vector<int> v[N];
void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    if (v[x].size() < v[y].size())
    {
        p[x] = y;
        for (int i = 0; i < v[x].size(); ++i)
            v[y].push_back(v[x][i]);
    }
    else
    {
        p[y] = x;
        for (int i = 0; i < v[y].size(); ++i)
            v[x].push_back(v[y][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
        v[i].push_back(i);
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        kpc(x, y);
    }
    int x = fi(1);
    for (int i = 0; i < v[x].size(); ++i)
        cout << v[x][i] << ' ';
    cout << endl;
    return 0;
}
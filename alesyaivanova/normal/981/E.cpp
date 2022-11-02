#include <bits/stdc++.h>

using namespace std;

bitset<10001> d[1 << 15];
vector<int> used[1 << 15];

void add(int v, int l, int r, int left, int right, int x)
{
    int m = (l + r) / 2;
    if (l == left && r == right)
    {
        d[v] |= (d[v] << x);
        used[v].push_back(x);
    }
    else if (right <= m)
        add(v * 2, l, m, left, right, x);
    else if (left >= m)
        add(v * 2 + 1, m, r, left, right, x);
    else
    {
        add(v * 2, l, m, left, m, x);
        add(v * 2 + 1, m, r, m, right, x);
    }
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    int m = (1 << 14);
    for (int i = 0; i < 2 * m; i++)
        d[i].set(0);
    for (int i = 0; i < q; i++)
    {
        int left, right, x;
        cin >> left >> right >> x;
        left--;
        add(1, 0, m, left, right, x);
    }
    for (int i = m - 1; i >= 1; i--)
    {
        for (int e : used[i])
        {
            d[i * 2] |= (d[i * 2] << e);
            d[i * 2 + 1] |= (d[i * 2 + 1] << e);
        }
        d[i] |= d[i * 2];
        d[i] |= d[i * 2 + 1];
    }
    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d[1].test(i))
            num++;
    }
    cout << num << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (d[1].test(i))
            cout << i << " ";
    }
}
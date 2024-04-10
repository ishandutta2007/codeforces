#include <bits/stdc++.h>

using namespace std;

int a[1 << 19];
int ne[1 << 19];
bool b[1 << 20];

void add(int v, int l, int r, int left, int right)
{
    int m = (l + r) / 2;
    if (l == left && r == right)
        b[v] = true;
    else if (right <= m)
        add(v * 2, l, m, left, right);
    else if (left >= m)
        add(v * 2 + 1, m, r, left, right);
    else
    {
        add(v * 2, l, m, left, m);
        add(v * 2 + 1, m, r, m, right);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k, d;
    cin >> n >> k >> d;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        while (cur < n && a[cur] - a[i] <= d)
            cur++;
        cur--;
        ne[i] = cur;
    }
    int m = (1 << 19);
    for (int i = 0; i < n; i++)
    {
        if (i >= 1)
        {
            bool y = false;
            for (int e = m + i - 1; e >= 1; e = e / 2)
            {
                if (b[e])
                {
                    y = true;
                    break;
                }
            }
            if (!y)
                continue;
        }
        if (ne[i] >= i + k - 1)
        {
            add(1, 0, m, i + k - 1, ne[i] + 1);
        }
    }
    bool y = false;
    for (int e = m + n - 1; e >= 1; e = e / 2)
    {
        if (b[e])
        {
            y = true;
            break;
        }
    }
    if (y)
        cout << "YES";
    else
        cout << "NO";
}
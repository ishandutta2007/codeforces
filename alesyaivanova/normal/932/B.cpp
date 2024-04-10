#include <iostream>
#include <algorithm>

using namespace std;

int g(int i)
{
    if (i <= 9)
        return i;
    int t = 1;
    while (i > 0)
    {
        int y = i % 10;
        if (y != 0)
            t *= y;
        i /= 10;
    }
    return g(t);
}

int main()
{
    int q;
    cin >> q;
    pair<int, int> b[2 * q];
    int ans[q];
    for (int i = 0; i < q; i++)
        ans[i] = -1;
    int t[q];
    for (int i = 0; i < q; i++)
    {
        cin >> b[i * 2].first >> b[i * 2 + 1].first >> t[i];
        b[i * 2].second = i;
        b[i * 2 + 1].second = i;
    }
    sort(b, b + 2 * q);
    int j = 0;
    int d[10] = {};
    for (int i = 1; i <= 1000000; i++)
    {
        int k = g(i);
        d[k]++;
        while (j < 2 * q && b[j].first == i)
        {
            if (ans[b[j].second] == -1)
            {
                ans[b[j].second] = d[t[b[j].second]];
                if (t[b[j].second] == k)
                    ans[b[j].second]--;
            }
            else
                ans[b[j].second] = d[t[b[j].second]] - ans[b[j].second];
            j++;
        }
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << endl;
}
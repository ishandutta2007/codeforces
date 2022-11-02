#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    pair<int, int> used[256];
    for (int i = 0; i < 256; i++)
        used[i].first = -1;
    for (int i = 0; i < n; i++)
    {
        if (used[a[i]].first != -1)
            cout << used[a[i]].first << " ";
        else
        {
            int j = a[i];
            while (j >= 0 && used[j].first == -1 && a[i] - j + 1 <= k)
                j--;
            int col = j + 1;
            if (j >= 0 && a[i] - j + 1 <= k && used[j].second + a[i] - j <= k)
            {
                col = used[j].first;
                cout << col << " ";
                int u = used[j].second + a[i] - j;
                for (int e = j; e <= a[i]; e++)
                {
                    used[e].first = col;
                    used[e].second = u;
                }
            }
            else
            {
                j++;
                cout << j << " ";
                int u = a[i] - j + 1;
                for (int e = j; e <= a[i]; e++)
                {
                    used[e].first = j;
                    used[e].second = u;
                }
            }
        }
    }
}
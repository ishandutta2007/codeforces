#include <bits/stdc++.h>
using namespace std;
const int N = 55;

int n;
char a[N];

int dist(char x, char y)
{
    if (x > y)
        swap(x, y);
    return min(y - x, x - 'A' + 'Z' - y + 1);
}

int main()
{
    cin >> n;
    cin >> a;
    int ans = N * 7;
    for (int i = 0; i < n; ++i)
    {
        if (i + 4 > n)
            break;
        for (int j = i + 1; j <= i + 1; ++j)
        {
            for (int k = j + 1; k <= j + 1; ++k)
            {
                for (int t = k + 1; t <= k + 1; ++t)
                {
                    ans = min(ans, dist(a[i], 'A') + dist(a[j], 'C') + dist(a[k], 'T') + dist(a[t], 'G'));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
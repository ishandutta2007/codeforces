#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
string a[N];

int d[N * 5], b[N * 5];
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        int m = a[i].size();

        int p = 0;
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == '(')
                ++p;
            else
                --p;
            if (p < 0)
            {
                break;
            }
        }
        if (p >= 0)
        {
            d[p]++;
            continue;
        }

        reverse(a[i].begin(), a[i].end());
        p = 0;
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == ')')
                ++p;
            else
                --p;
            if (p < 0)
            {
                break;
            }
        }
        if (p >= 0)
        {
            b[p]++;
            continue;
        }
    }
    int ans = d[0] / 2;
    for (int i = 1; i < N * 5; ++i)
        ans += min(d[i], b[i]);
    cout << ans << endl;
    return 0;
}
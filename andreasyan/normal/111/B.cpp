#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N];
int b[N];
int last[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        int ans = 0;
        for (int j = 1; j * j <= a[i]; ++j)
        {
            if (a[i] % j == 0)
            {
                if (j == a[i] / j)
                {
                    if (last[j] < i - b[i])
                        ++ans;
                    last[j] = i;
                }
                else
                {
                    if (last[j] < i - b[i])
                        ++ans;
                    last[j] = i;
                    if (last[a[i] / j] < i - b[i])
                        ++ans;
                    last[a[i] / j] = i;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
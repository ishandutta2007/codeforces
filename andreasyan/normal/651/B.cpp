#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    int ans = 0;
    while (1)
    {
        int q = 0;
        for (int i = 1; i < N; ++i)
        {
            if (a[i])
            {
                ++q;
                --a[i];
            }
        }
        if (q == 0)
            break;
        ans += (q - 1);
    }
    cout << ans << endl;
    return 0;
}
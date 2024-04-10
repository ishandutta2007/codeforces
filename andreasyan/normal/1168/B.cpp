#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n;
char a[N];

int main()
{
    cin >> a;
    n = strlen(a);
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            bool z = false;
            for (int k = i; k < j; ++k)
            {
                if ((j + k) % 2 == 0 && a[j] == a[k] && a[j] == a[(j + k) / 2])
                {
                    z = true;
                    break;
                }
            }
            if (z)
            {
                ans += (n - j);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
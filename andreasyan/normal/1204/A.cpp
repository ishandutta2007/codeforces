#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
char a[N];

int main()
{
    int ans = 0;
    cin >> a;
    n = strlen(a);
    for (int i = 1; i <= n; i += 2)
    {
        ++ans;
        if (i == n)
        {
            bool z = true;
            for (int j = 1; j < n; ++j)
            {
                if (a[j] == '1')
                {
                    z = false;
                    break;
                }
            }
            if (z)
                --ans;
        }
    }
    cout << ans << endl;
    return 0;
}
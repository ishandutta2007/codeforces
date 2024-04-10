#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n, m;
int a[N];

int main()
{
    cin >> n >> m;
    a[0] = 1;
    for (int i = 1; i <= n / 2; ++i)
        a[i] = i;
    if (n % 2 == 0)
    {
        for (int i = n / 2 + 1; i <= n; ++i)
        {
            a[i] = a[i - 1] - 1;
        }
    }
    else
    {
        a[n / 2 + 1] = a[n / 2];
        for (int i = n / 2 + 2; i <= n; ++i)
            a[i] = a[i - 1] - 1;
    }
    cout << a[m] << endl;
    return 0;
}
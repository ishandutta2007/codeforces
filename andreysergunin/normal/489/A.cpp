#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, n, m, t, a[10000];
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    cout << n - 1 << '\n';
    for (i = 0; i < n - 1; i++)
    {
        m = 1500000000;
        t = -1;
        for (j = i; j < n; j++)
            if (m > a[j])
            {
                t = j;
                m = a[j];
            }
        cout << i << ' ' << t << '\n';
        a[t] = a[i];
    }
    return 0;
}
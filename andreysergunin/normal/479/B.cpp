#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;


int main()
{
    long n, k, i, j, qma, qmi, a[2000], u[2000], v[2000], mi, ma, ans;
    cin >> n >> k;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < k; i++)
    {
        mi = 1000000000;
        ma = 0;
        for (j = 0; j < n; j++)
        {
            if (a[j] < mi)
            {
                qmi = j;
                mi = a[j];
            }
            if (a[j] > ma)
            {
                qma = j;
                ma = a[j];
            }
        }
        u[i] = qma;
        v[i] = qmi;
        a[qma]--;
        a[qmi]++;
    }
    for (i = 0; i < n; i++)
    {
        mi = 1000000000;
        ma = 0;
        for (j = 0; j < n; j++)
        {
            if (a[j] < mi)
            {
                qmi = j;
                mi = a[j];
            }
            if (a[j] > ma)
            {
                qma = j;
                ma = a[j];
            }
        }
    }
    cout << a[qma] - a[qmi] << ' ';
    ans = 0;
    for (i = 0; i < k; i++)
        if (u[i] != v[i])
            ans++;
    cout << ans << '\n';
    for (i = 0; i < ans; i++)
        cout << u[i] + 1 << ' ' << v[i] + 1 << '\n';
}
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, mmin;
    mmin = 100000000;
    cin >> n >> m;
    int a[10000];
    for (int i = 0; i < m; i++)
        cin >> a[i];
    sort(a, a+m);
    if (n == m)
        mmin = a[m - 1] - a[0];
    for (int i = 0; i <= (m - n); i++)
        if (a[i + n - 1] - a[i] < mmin)
            mmin = a[i + n - 1] - a[i];
    cout << mmin;
    return 0;
}
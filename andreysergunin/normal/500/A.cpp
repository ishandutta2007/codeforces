#include<bits/stdc++.h>

using namespace std;
const int maxn = 100000;

int main()
{
    int t, n, a[maxn], d[maxn];
    cin >> n >> t;
    for (int i = 0; i < n - 1; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        d[i] = 0;
    d[0] = 1;
    for (int i = 0; i < n - 1; i++)
        if (d[i] == 1)
            d[i + a[i]] = 1;
    if (d[t - 1] == 1)
        cout << "YES";
    else
        cout << "NO";
}
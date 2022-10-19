#include <bits/stdc++.h>
using namespace std;
const int N = 202;
 
int n;
int a[N];
 
bool solv()
{
    cin >> n;
    int j;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] == 1)
            j = i;
    }
    bool z = true;
    for (int i = j + 1; i <= n; ++i)
    {
        if (a[i] != a[i - 1] + 1)
        {
            z = false;
            break;
        }
    }
    for (int i = 2; i < j; ++i)
    {
        if (a[i] != a[i - 1] + 1)
        {
            z = false;
            break;
        }
    }
    if (z)
        return true;
    z = true;
    for (int i = j - 1; i >= 1; --i)
    {
        if (a[i] != a[i + 1] + 1)
        {
            z = false;
            break;
        }
    }
    for (int i = n - 1; i > j; --i)
    {
        if (a[i] != a[i + 1] + 1)
        {
            z = false;
            break;
        }
    }
    return z;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--)
    {
        if (solv())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int a[100010];
int b[100010];

int main()
{
    int n, i, x;
    cin >> n;
    if (n % 2 == 1)
    {
        cout << "NO";
        return 0;
    }
    for (i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    x = a[0];
    for (i = 0; i < n; i++)
        a[i] = a[i] - x;
    for (i = 1; i < n; i++)
        if (a[i - 1] + 1 < a[i])
        {
            cout << "NO";
            return 0;
        }
    for (i = 0; i < n; i++)
        b[a[i]]++;

    x = a[n - 1];
    for (i = x - 1; i >= 0; i--)
    {
        b[i] -= b[i + 1];
        if (i != 0 && b[i] < 1)
        {
            cout << "NO";
            return 0;
        }
    }
    if (b[0] != 0)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";

    return 0;
}
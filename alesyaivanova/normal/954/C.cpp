#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x = 1;
    int y = 1;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        if (abs(a[i + 1] - a[i]) != 1)
        {
            if (y == 1)
            {
                y = abs(a[i + 1] - a[i]);
            }
            else if (abs(a[i + 1] - a[i]) != y)
            {
                cout << "NO";
                return 0;
            }
        }
    }
    if (y > 1000000000 || y == 0)
    {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        x = max(x, (a[i] + y - 1) / y);
    }
    if (x > 1000000000)
    {
        cout << "NO";
    }
    if (y != 1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if ((a[i + 1] == a[i] + 1) && (a[i] % y == 0))
            {
                cout << "NO";
                return 0;
            }
            if ((a[i + 1] == a[i] - 1) && (a[i + 1] % y == 0))
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES\n" << x << " " << y;
}
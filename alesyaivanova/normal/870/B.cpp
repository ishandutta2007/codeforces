#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if (k == 1)
    {
        long long mi = 1000000000;
        for (int i = 0; i < n; i++)
        {
            long long a;
            cin >> a;
            if (a < mi)
                mi = a;
        }
        cout << mi;
        return 0;
    }
    if (k == 2)
    {
        long long a, x, y;
        cin >> x;
        for (int i = 1; i < n - 1; i++)
            cin >> a;
        cin >> y;
        cout << max(x, y);
        return 0;
    }
    long long ma = -1000000000;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        if (a > ma)
            ma = a;
    }
    cout << ma;
    return 0;
}
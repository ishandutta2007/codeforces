#include <iostream>

using namespace std;

int main()
{
    long long n, x, y;
    cin >> n >> x >> y;
    if (n > y)
    {
        cout << -1;
        return 0;
    }
    long long sum = n - 1;
    sum += (y - n + 1) * (y - n + 1);
    if (sum < x)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << 1 << "\n";
    }
    cout << y - n + 1;
    return 0;
}
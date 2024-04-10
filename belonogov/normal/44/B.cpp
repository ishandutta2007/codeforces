#include <iostream>

using namespace std;

int main()
{
    int n, a, b, c, i, j, k, ans = 0;
    cin >> n >> a >> b >> c;
    for (i = 0; i <= (n / 2); i++)
    {
        k = n - i *  2;
        for (j = 0; j <= k; j++)
        {
            if ((k - j) * 2 <= a && j <= b && i <= c)
                ans++;
        }
    }
    cout << ans;
    return 0;
}
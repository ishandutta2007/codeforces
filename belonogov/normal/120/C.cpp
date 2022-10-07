#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
int a[10000];

int main()
{
    freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
    int k, n, i, sum = 0, x, d;
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        d = 0;
        while (d != 3 && x >= k)
        {
            x -= k;
            d++;
        }
        sum += x;
    }
    cout << sum;

    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long sum = 0, k, i, n;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> k;
        sum += k * i;
        sum -= (i - 1);
    }
    cout << sum;
    return 0;
}
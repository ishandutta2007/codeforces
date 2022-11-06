#include <iostream>

using namespace std;

long long a[7],n,i;

int main()
{
    cin >> a[1] >> a[2] >> n;
    for(i=3;i<=6;i++) a[i] = a[i-1]-a[i-2];

    n = n % 6;
    if (n == 0) n = 6;

    n = a[n];
    while (n < 0) n = n + 1000000007;
    cout << n % 1000000007;

    return 0;
}
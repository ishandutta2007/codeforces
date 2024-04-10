#include <iostream>

using namespace std;


int main()
{
    int i, n, a[200], l, r, sum;
    cin >> n;
    for (i = 0; i < n - 1; i++)
        cin >> a[i];
    cin >> l >> r;
    sum = 0;
    for (i = l - 1; i < r - 1; i++)
        sum += a[i];
    cout << sum;
    return 0;
}
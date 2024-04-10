#include <bits/stdc++.h>
using namespace std;

int a[3];

int main()
{
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[2] < a[0] + a[1])
    {
        cout << 0 << endl;
        return 0;
    }
    cout << a[2] - (a[0] + a[1]) + 1 << endl;
    return 0;
}
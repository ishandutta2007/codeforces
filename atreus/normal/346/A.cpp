#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long a[100 + 1];
    long long n, z, m = 0, s;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    z = a[0];
    m = a[0];
    for (int i = 1; i < n; i++) {
        z = __gcd(a[i], z);
        if (a[i] > m)
            m = a[i];
    }
    s = m / z;
    s = s - n;
    if (s % 2 == 1)
        cout << "Alice" << endl;
    else if (s % 2 == 0)
        cout << "Bob" << endl;
}
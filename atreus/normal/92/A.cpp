#include <iostream>

using namespace std;

int main ()
{
    int n, m, s = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
       s += i;
    m = m % s;
    for (int i = 1; i <= n; i++)
        if (m - i >= 0)
            m -= i;
        else
            break;
    cout << m;
}
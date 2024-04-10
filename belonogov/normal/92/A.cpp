#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, m, i;
    cin >> n >> m;
    m = m % (n * (n + 1) / 2);
    i = 1;
    while (m >= i)
    {
        m = m - i;
        i++;
    }
    cout << m;

    return 0;
}
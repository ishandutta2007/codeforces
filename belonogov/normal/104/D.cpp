#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long n, k, p, i, d, n1, k1;
    cin >> n >> k >> p;
    n1 = n;
    k1 = k;
    if (n % 2 == 1)
    {
        n1 = n - 1;
        k1 = k - 1;
    }
    for (i = 0; i < p; i++)
    {
        cin >> d;
        if (n1 + 1 == d)
            if (k == 0)
                cout << ".";
            else
                cout << "X";
        else
        if (n1 >= 2 * k)
            if (d % 2 == 0 && (n1 - d) / 2 + 1 <= k1)
                cout << "X";
            else
                cout << ".";
        else
            if (d % 2 == 1 && (d / 2 + 1) + k1 <= n1)
                cout << ".";
            else
                cout << "X";
    }
    return 0;
}
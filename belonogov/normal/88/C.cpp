#include <iostream>
#include <cstdio>

using namespace std;

int n, i;

int main()
{
     long long a, b, d, a0;
    long long k, sum, a1, b1, suma, sumb;
    k = 0;
    cin >> a >> b;
    a0 = a;
    if (a < b)
    {
        d = a;
        a = b;
        b = d;
    }
    sum = a * b;
    a1 = a;
    b1 = b;
    suma = 0;
    sumb = 0;
    while (k < sum)
    {
        if (a1 - k > b1 - k)
        {
            sumb = sumb + b1 - k;
            k = b1;
            b1 = b1 + b;

        }else
        {
            suma = suma + a1 - k;
            k = a1;
            a1 = a1 + a;
        }
    }
    if (a0 == a)
    {
        if (suma > sumb) cout << "Dasha";
        if (suma < sumb) cout << "Masha";
        if (suma == sumb) cout << "Equal";
    }
    if (a0 != a)
    {
        if (suma < sumb) cout << "Dasha";
        if (suma > sumb) cout << "Masha";
        if (suma == sumb) cout << "Equal";
    }
    return 0;
}
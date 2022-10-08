#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long  k, l, k1, i = 0;
    cin >> k >> l;
    k1 = k;
    while (k < l)
    {
        k *= k1;
        i++;
    }
    if (k == l)
    {
        cout << "YES" << "\n";
        cout << i;
    }
    else
        cout << "NO";
    return 0;
}
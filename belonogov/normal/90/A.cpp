#include <iostream>
#include <cstdio>

using namespace std;

int n, i;

int main()
{
     int a, b, c, k, k1, k2;
    cin >> a >> b >> c;
    k = (((a + 1) / 2) - 1) * 3;
    k1 = (((b + 1) / 2) - 1) * 3 + 1;
    k2 = (((c + 1) / 2) - 1) * 3 + 2;
    if (k < k1) k = k1;
    if (k < k2) k = k2;
    cout << (k + 30);



    return 0;
}
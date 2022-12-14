#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a1, a2, a3, b1, b2, b3;
    float n;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
    a1 += a2 + a3;
    b1 += b2 + b3;
    if((int)ceil(a1 / 5.0) + (int)ceil(b1 / 10.0) > n)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}
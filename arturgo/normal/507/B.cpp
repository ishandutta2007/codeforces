#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;

    long long distC = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    long double dist = sqrt(distC);

    if((dist / (2 * r)) - (int)(dist / (2 * r)) == 0)
        cout << (int)(dist / (2 * r)) << endl;
    else
        cout << (int)(dist / (2 * r)) + 1 << endl;
    return 0;
}
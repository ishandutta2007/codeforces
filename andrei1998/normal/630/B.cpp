#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    long double n, t;
    cin >> n >> t;

    cout << fixed << setprecision(20) << n * pow(1.000000011l, t) << endl;
    return 0;
}
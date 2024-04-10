#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    a -= '0';
    b -= '0';
    c -= '0';
    d -= '0';
    e -= '0';

    long long int n = 10000 * a + 1000 * c + 100 * e + 10 * d + b;

    long long int aux = (1ll * (n * n * n)) % 100000;
    aux = (aux * (n * n)) % 100000;

    cout << setfill('0') << setw(5) << aux << endl;
    return 0;
}
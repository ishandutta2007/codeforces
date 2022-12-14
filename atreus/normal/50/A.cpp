#include <iostream>

using namespace std;

int main ()
{
    int n, m, a;
    cin >> n >> m;
    if (n % 2 == 0)
        a = (n/2)*m;
    else
        a = ((n/2)*m)+m/2;
    cout << a;
}
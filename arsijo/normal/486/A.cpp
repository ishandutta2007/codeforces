#include <iostream>

using namespace std;

int main()
{
    long long int n;
    cin >> n;
    if (n % 2 == 1)
        cout << "-";
    cout << ((n / 2) + (n % 2)) << endl;
}
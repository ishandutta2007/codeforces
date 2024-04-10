#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << (n / 5) + (bool)(n % 5) << '\n';
    return 0;
}
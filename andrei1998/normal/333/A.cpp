#include <iostream>

#define lint long long int
using namespace std;

int main()
{
    lint n;
    cin >> n;
    while (n % 3 == 0)
        n /= 3;
    cout << (n + 2) / 3 << '\n';
    return 0;
}
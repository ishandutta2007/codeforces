#include <iostream>

using namespace std;

int main()
{
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    n /= 2;
    if ((k1 == n || k1 == n + 1) && (k2 == n || k2 == n + 1))
        cout << "NO";
    else
        cout << "YES";
    return 0;
}
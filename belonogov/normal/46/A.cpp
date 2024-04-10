#include <iostream>

using namespace std;

int main()
{
    int i, n, uk;
    cin >> n;
    uk = 0;
    for (i = 1; i < n; i++)
    {
        uk = (uk + i) % n;
        cout << (uk + 1) << " ";
    }

    return 0;
}
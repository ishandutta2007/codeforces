#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;
    int i = 1, j = 1, k = 1;
    while (j < n)
    {
        i *= 2;
        j += i;
        ++k;
    }
    cout << k << endl;

    return 0;
}
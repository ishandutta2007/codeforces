#include <iostream>

using namespace std;

int main()
{
    int i, j, k, x;
    cin >> k;
    for (i = 1; i < k; i++)
    {
        for (j = 1; j < k; j++)
        {
            x = i * j;
            if (x / k != 0)
                cout << x/k;
            cout << x % k << " ";
        }
        cout << "\n";
    }
    return 0;
}
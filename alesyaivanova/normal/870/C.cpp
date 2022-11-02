#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        long long a;
        cin >> a;
        if ((a < 4) || (a == 5) || (a == 7) || (a == 11))
        {
            cout << -1 << endl;
        }
        else if (a % 2 == 0)
        {
            cout << a / 4 << endl;
        }
        else
        {
            cout << a / 4 - 1 << endl;
        }
    }
}
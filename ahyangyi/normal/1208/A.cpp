#include <iostream>

using namespace std;

int main()
{
    int t;

    cin >> t;
    for (int ct = 0; ct < t; ++ct)
    {
        int a, b, n;

        cin >> a >> b >> n;
        switch (n % 3)
        {
            case 0:
                cout << a << endl;
                break;
            case 1:
                cout << b << endl;
                break;
            case 2:
                cout << (a ^ b) << endl;
                break;
        }
    }

    return 0;
}
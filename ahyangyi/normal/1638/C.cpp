#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int ct = 0; ct < t; ++ct)
    {
        int n;
        cin >> n;

        int m = 0;
        int r = 0;
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            if (a > m) m = a;

            if (m == i + 1)
            {
                ++r;
            }
        }

        cout << r << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int ct = 0; ct < t; ++ct)
    {
        int n, prev_odd = -1, prev_even = 0;
        bool ok = true;
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            if (a % 2 == 1)
            {
                if (prev_odd > a)
                {
                    ok = false;
                }
                prev_odd = a;
            }
            else
            {
                if (prev_even > a)
                {
                    ok = false;
                }
                prev_even = a;
            }
        }

        if (ok)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
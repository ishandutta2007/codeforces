#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    while (true)
    {
        string s;
        cin >> s;
        if (s[0] != 's')
            return 0;
        cout << "? 0 1" << endl;
        char ans;
        cin >> ans;
        if (ans == 'x')
        {
            cout << "! 1" << endl;
            continue;
        }
        int left = 1;
        int right = 2;
        while (true)
        {
            cout << "? " << left << " " << right << endl;
            cin >> ans;
            if (ans == 'x')
                break;
            left *= 2;
            right *= 2;
        }
        while (right - left > 1)
        {
            int m = (left + right) / 2;
            cout << "? " << left << " " << m << endl;
            cin >> ans;
            if (ans == 'x')
                right = m;
            else
                left = m;
        }
        cout << "! " << right << endl;
    }
}
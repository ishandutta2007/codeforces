#include <bits/stdc++.h>

using namespace std;

int a[10000];

main()
{
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] != '1' && s[i] != '4')
        {
            cout << "NO";
            return 0;
        }
        if (s[i] == '4')
        {
            if (s[i - 1] != '1' && s[i - 2] != '1')
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}
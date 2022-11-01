#include <bits/stdc++.h>

using namespace std;

int a[10000];

main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int s1, s2;
    s1 = s2 = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] != '4' && s[i] != '7')
        {
            cout << "NO";
            return 0;
        }
        if (i < n / 2)
            s1 += s[i];
        else
            s2 += s[i];
    }
    if (s1 != s2)
        cout << "NO";
    else
        cout << "YES";
}
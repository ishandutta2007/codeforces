#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    bool u1 = false;
    bool u2 = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            if (u2)
            {
                cout << "1 4\n";
                u2 = false;
            }
            else
            {
                cout << "3 4\n";
                u2 = true;
            }
        }
        else
        {
            if (u1)
            {
                cout << "1 3\n";
                u1 = false;
            }
            else
            {
                cout << "1 1\n";
                u1 = true;
            }
        }
    }
}
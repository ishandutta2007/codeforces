#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1)
    {
        if (s[0] == '1')
            cout << "Yes";
        else
            cout << "No";
        return 0;
    }
    if (s[0] == '0' && s[1] == '0')
    {
        cout << "No";
        return 0;
    }
    if (s[n - 2] == '0' && s[n - 1] == '0')
    {
        cout << "No";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1 && s[i] == '1' && s[i + 1] == '1')
        {
            cout << "No";
            return 0;
        }
        if (i < n - 1 && i > 0 && s[i] == '0' && s[i - 1] == '0' && s[i + 1] == '0')
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
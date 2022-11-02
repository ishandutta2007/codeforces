#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    bool t = true;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
            t = false;
    }
    if (t)
    {
        cout << 0;
        return 0;
    }
    t = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[n - 1 - i])
            t = false;
    }
    if (t)
        cout << n - 1;
    else
        cout << n;
}
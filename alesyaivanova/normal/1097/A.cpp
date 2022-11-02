#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    bool u = false;
    for (int i = 0; i < 5; i++)
    {
        string a;
        cin >> a;
        if (a[0] == s[0] || a[1] == s[1])
            u = true;
    }
    if (u)
        cout << "YES";
    else
        cout << "NO";
}
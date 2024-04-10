#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 5009;
int z[MAX_N];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 1; i <= n - 1; i++)
    {
        string cur = s.substr(i, n) + s.substr(0, i);
        bool u = false;
        for (int e = 0; e < n; e++)
        {
            if (cur[e] != s[e])
                u = true;
        }
        if (!u)
            continue;
        for (int e = 0; e < n; e++)
        {
            if (cur[e] != cur[n - 1 - e])
                u = false;
        }
        if (!u)
            continue;
        cout << 1;
        return 0;
    }
        bool t = false;
        for (int e = 1; e < n / 2; e++)
        {
            if (s[e] != s[e - 1])
                t = true;
        }
        if (t && n > 3)
            cout << 2;
        else
            cout << "Impossible";

}
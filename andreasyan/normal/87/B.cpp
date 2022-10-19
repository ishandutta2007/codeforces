#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main()
{
    mp["void"] = 0;
    int q;
    cin >> q;
    while (q--)
    {
        string ty;
        cin >> ty;
        if (ty == "typedef")
        {
            string a, b;
            cin >> a >> b;

            if (b == "void")
                continue;

            int t = 0;
            while (a[a.size() - 1] == '*')
            {
                ++t;
                a.erase(--a.end());
            }
            while (a[0] == '&')
            {
                --t;
                a.erase(a.begin());
            }
            if (mp.find(a) == mp.end() || mp[a] == -1)
            {
                mp[b] = -1;
                continue;
            }
            t += mp[a];
            if (t < 0)
            {
                mp[b] = -1;
                continue;
            }
            mp[b] = t;
        }
        else
        {
            string a;
            cin >> a;
            int t = 0;
            while (a[a.size() - 1] == '*')
            {
                ++t;
                a.erase(--a.end());
            }
            while (a[0] == '&')
            {
                --t;
                a.erase(a.begin());
            }
            if (mp.find(a) == mp.end() || mp[a] == -1)
            {
                cout << "errtype" << endl;
                continue;
            }
            t += mp[a];
            if (t < 0)
            {
                cout << "errtype" << endl;
                continue;
            }
            cout << "void";
            for (int i = 0; i < t; ++i)
                cout << '*';
            cout << endl;
        }
    }
    return 0;
}
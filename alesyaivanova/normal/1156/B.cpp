#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ss second
#define ff first

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        string s;
        cin >> s;
        map<char, int> m;
        for (int i = 0; i < (int)s.size(); i++)
            m[s[i]]++;
        bool u = true;
        auto e0 = m.begin();
        auto e1 = e0;
        e1++;
        while (e1 != m.end())
        {
            if ((*e1).ff != (*e0).ff + 1)
                u = false;
            e0++; e1++;
        }
        if (u && (int)m.size() <= 3 && (int)m.size() != 1)
        {
            cout << "No answer\n";
            continue;
        }
        if ((int)m.size() == 3)
        {
            e0 = m.begin();
            e1 = e0;
            e1++;
            if ((*e0).ff + 1 == (*e1).ff)
            {
                for (int i = 0; i < (*e0).ss; i++)
                    cout << (*e0).ff;
                e1++;
                for (int i = 0; i < (*e1).ss; i++)
                    cout << (*e1).ff;
                e1--;
                for (int i = 0; i < (*e1).ss; i++)
                    cout << (*e1).ff;
                cout << "\n";
                continue;
            }
        }
            e0 = m.begin();
            e0++;
            while (e0 != m.end())
            {
                for (int i = 0; i < (*e0).ss; i++)
                    cout << (*e0).ff;
                e0++;
                if (e0 == m.end())
                    break;
                e0++;
            }
            e0 = m.begin();
            while (e0 != m.end())
            {
                for (int i = 0; i < (*e0).ss; i++)
                    cout << (*e0).ff;
                e0++;
                if (e0 == m.end())
                    break;
                e0++;
            }
        cout << "\n";
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    string s;
    cin >> s;
    int n = s.size();
    set <char> c;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' || c.count(s[i] - 1))
        {
            c.insert(s[i]);
        }
        else
        {
            cout << "NO\n";
            return 0;
        }
    }
    if (c.size() == *c.rbegin() - 'a' + 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
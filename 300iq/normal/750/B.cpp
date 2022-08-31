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
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        int l;
        string s;
        cin >> l >> s;
        if (s[0] == 'W' || s[0] == 'E')
        {
            if (x == 0 || x == 20000)
            {
                cout << "NO\n";
                return 0;
            }
        }
        if (s[0] == 'S')
        {
            x += l;
            if (x > 20000)
            {
                cout << "NO\n";
                return 0;
            }
        }
        if (s[0] == 'N')
        {
            x -= l;
            if (x < 0)
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    if (x != 0)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
}
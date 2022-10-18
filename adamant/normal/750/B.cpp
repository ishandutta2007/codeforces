#include <bits/stdc++.h>

using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x = 0, y = 0;
    int maxn = 20000;
    for(int i = 0; i < n; i++)
    {
        string type;
        int num;
        cin >> num;
        cin >> type;
        if(x == 0)
        {
            if(type[0] != 'S')
            {
                cout << "NO\n";
                return 0;
            }
            x += num;
        }
        else if(x == 20000)
        {
            if(type[0] != 'N')
            {
                cout << "NO\n";
                return 0;
            }
            x -= num;
        }
        else if(type[0] == 'S')
            x += num;
        else if(type[0] == 'N')
            x -= num;
        if(x < 0 || x > 20000)
        {
            cout << "NO\n";
            return 0;
        }

    }
    if(x == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
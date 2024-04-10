#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a[2];
    string b[2];
    cin >> a[0] >> a[1] >> b[0] >> b[1];
    for(int i = 0; i < 16; i++)
    {
        if(a[0] == b[0] && a[1] == b[1])
        {
            cout << "YES\n";
            return 0;
        }
        for(int x = 0; x < 2; x++)
            for(int y = 0; y < 2; y++)
                if(a[x][y] == 'X')
                {
                    if(x == 0 && y == 0)
                        swap(a[0][0], a[0][1]);
                    else if(x == 0 && y == 1)
                        swap(a[0][1], a[1][1]);
                    else if(x == 1 && y == 1)
                        swap(a[1][1], a[1][0]);
                    else if(x == 1 && y == 0)
                        swap(a[1][0], a[0][0]);
                    goto out;
                }
        out:;
        //cout << i << "\n" << a[0] << "\n" << a[1] << "\n\n";
    }
    cout << "NO\n";
}
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int a[2000][2000];

int main()
{
    string s;
    cin >> s;
    if(s.size() <= 1)
    {
        cout << "OK";
        return 0;
    }
    int x = 1000;
    int y = 1000;
    a[x][y] = 1;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'R')
            x++;
        if(s[i] == 'L')
            x--;
        if(s[i] == 'U')
            y++;
        if(s[i] == 'D')
            y--;
        if(a[x][y] == 1)
            {cout << "BUG";return 0;}
        a[x][y] = 1;
    }
    for(int i = 10; i < 1900; i++)
        for(int j = 10; j < 1900; j++)
        {
            if(a[i][j] + a[i][j + 1] + a[i][j - 1] + a[i + 1][j] + a[i - 1][j] >= 4)
                {cout << "BUG";return 0;}
            if(a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1] == 4)
                {cout << "BUG";return 0;}
        }
    if(fabs(1000 - x) + fabs(1000 - y) <= 1)
        {cout << "BUG";return 0;}
    cout << "OK";
    return 0;
}
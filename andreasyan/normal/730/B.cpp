#include <bits/stdc++.h>
using namespace std;
const int N = 2000006;

map<int, map<int, char> > mp;
char qry(int x, int y)
{
    if (mp[x].find(y) == mp[x].end())
    {
        cout << "? " << x << ' ' << y << endl;
        char ans;
        cin >> ans;
        mp[x][y] = ans;
        if (mp[x][y] == '=')
            mp[y][x] = '=';
        else if (mp[x][y] == '>')
            mp[y][x] = '<';
        else
            mp[y][x] = '>';
    }
    return mp[x][y];
}

int n;
int minu[N], maxu[N];
void solv()
{
    mp.clear();
    cin >> n;
    if (n == 1)
    {
        cout << "! 1 1" << endl;
        return;
    }
    bool z = false;
    if (n % 2 == 1)
    {
        --n;
        z = true;
    }
    for (int i = 1; i <= n; i += 2)
    {
        char ans;
        cout << "? " << i << ' ' << i + 1 << endl;
        cin >> ans;
        if (ans == '>')
        {
            maxu[i] = i;
            minu[i] = i + 1;
        }
        else
        {
            maxu[i] = i + 1;
            minu[i] = i;
        }
    }
    int yminu = minu[1];
    int ymaxu = maxu[1];
    for (int i = 3; i <= n; i += 2)
    {
        char ans;
        cout << "? " << minu[i] << ' ' << yminu << endl;
        cin >> ans;
        if (ans == '<')
            yminu = minu[i];
        cout << "? " << maxu[i] << ' ' << ymaxu << endl;
        cin >> ans;
        if (ans == '>')
            ymaxu = maxu[i];
    }
    if (z)
    {
        char ans;
        cout << "? " << n + 1 << ' ' << yminu << endl;
        cin >> ans;
        if (ans == '<')
            yminu = n + 1;
        cout << "? " << n + 1 << ' ' << ymaxu << endl;
        cin >> ans;
        if (ans == '>')
            ymaxu = n + 1;
    }
    cout << "! " << yminu << ' ' << ymaxu << endl;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}
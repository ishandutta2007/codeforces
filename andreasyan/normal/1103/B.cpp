#include <bits/stdc++.h>
using namespace std;

char qry(int x, int y)
{
    cout << "? " << x << ' ' << y << endl;
    char ans;
    cin >> ans;
    if (ans == 'e')
        exit(0);
    return ans;
}

void solv()
{
    int x = 1;
    while (1)
    {
        if (qry(x - 1, x + x - 1) == 'x')
            break;
        x *= 2;
    }
    int l = x, r = x + x - 1;
    while ((r - l + 1) != 1)
    {
        int m = (l + r) / 2;
        if (qry(x - 1, m) == 'x')
            r = m;
        else
            l = m + 1;
    }
    cout << "! " << l << endl;
}

int main()
{
    while (1)
    {
        string s;
        cin >> s;
        if (s == "end")
            break;
        else if (s == "mistake")
            break;
        else
            solv();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    long long x = 1, y = 1;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "UR")
            ++x;
        else if (s == "UL")
            ++y;
        else if (s == "DR")
            ++y;
        else if (s == "DL")
            ++x;
        else
        {
            ++x;
            ++y;
        }
    }
    cout << x * y << endl;
    return 0;
}
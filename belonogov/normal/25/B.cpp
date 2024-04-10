#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
int  a[10][10];

int main()
{
    int n, i;
    string s;
    cin >> n;
    cin >> s;
    if (n % 2 == 0)
        for (i = 0; i < n / 2; i++)
        {
            cout << s[i * 2]  <<  s[i * 2 + 1];
            if (i != n / 2 - 1)
                cout << "-";

        }
    else
    {
        for (i = 0; i < n / 2 - 1; i++)
        {
            cout << s[i * 2]  <<  s[i * 2 + 1];
            if (i != n / 2 - 1)
                cout << "-";

        }
        cout <<  s[n - 3] << s[n - 2] << s[n - 1];

    }
    return 0;
}
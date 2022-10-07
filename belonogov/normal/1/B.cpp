#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//vector <int> a;
int a[100000];
int b[100000];

int main()
{
   int n, i, j, k, d, m;
    string s1, s;
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> s;
        n = s.length();
        j = 0;
        while (s[j] != 'C' && j < n)
            j++;
        if (s[0] == 'R' && s[1] >= '0' && s[1] <= '9' && j >= 2 && s[j] == 'C')
        {
            d = 0;
            for (k = j + 1; k < n; k++)
                d = d * 10 + s[k] - '0';
            s1 = "";
            while (d != 0)
            {
                s1 += (d - 1) % 26 + 'A';
                d = (d - 1) / 26;
            }
            for (k = s1.length() - 1; k >= 0; k--)
                cout << s1[k];
            for (k = 1; k < j; k++)
                cout << s[k];
            cout << "\n";
        }
        else
        {
            j = 0;
            d = 0;
            while (s[j] >= 'A' && s[j] <= 'Z')
            {
                d = d * 26 + s[j] - 'A' + 1;
                j++;
            }
            cout << "R";
            for (; j < n; j++)
                cout << s[j];
            cout << "C";
            cout << d;
            cout << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int j, i = 1;
    while (s[i] != '.')
    {
        i++;
    }
    if (s[i - 1] == '9')
    {
        cout << "GOTO Vasilisa.";
        return 0;
    }
    if (s[i + 1] >= '5')
    {
        j = 0;
        while(j < i - 1)
        {
           cout << s[j];
           j++;
        }
        if (s[i - 1] == '0')
            cout << '1';
        if (s[i - 1] == '1')
            cout << '2';
        if (s[i - 1] == '2')
            cout << '3';
        if (s[i - 1] == '3')
            cout << '4';
        if (s[i - 1] == '4')
            cout << '5';
        if (s[i - 1] == '5')
            cout << '6';
        if (s[i - 1] == '6')
            cout << '7';
        if (s[i - 1] == '7')
            cout << '8';
        if (s[i - 1] == '8')
            cout << '9';
        }

    if (s[i + 1] < '5')
    {
        j = 0;
        while(j < i)
        {
           cout << s[j];
           j++;
        }
    }

    return 0;

}
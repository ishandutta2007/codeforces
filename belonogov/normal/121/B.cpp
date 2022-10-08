#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int n, k, i;
    string s;
    cin >> n >> k;
    cin >> s;
    i = 0;
    while (k > 0 && ! (i == n - 1))
    {

        while(i < n - 1 && (! (s[i] == '4' && s[i + 1] == '7')))
            i++;
        if (i == n - 1)
            continue;
        if (i % 2 == 0)
        {
            s[i] = '4';
            s[i + 1] = '4';
            k--;
            if (i + 2 < n && s[i + 2] == '7')
            {
                if (k % 2 == 0)
                {
                    cout << s;
                    return 0;
                }
                else
                {
                    s[i + 1] = '7';
                    cout << s;
                    return 0;
                }
            }
        }
        if (i % 2 == 1)
        {
            s[i] = '7';
            s[i + 1] = '7';
            k--;
            if (i != 0 && s[i - 1] == '4')
            {
                if (k % 2 == 0)
                {
                    cout << s;
                    return 0;
                }
                else
                {
                    s[i] = '4';
                    cout << s;
                    return 0;
                }
            }
        }
    }
    cout << s;

    return 0;
}
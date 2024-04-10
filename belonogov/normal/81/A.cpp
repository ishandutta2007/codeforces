#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;


int main()
{
    int i, n, uk = 0;
    string s, s1;
    cin >> s;
    s1 = s;
    n = s.length();
    for (i = 0; i < n; i++)
    {
        if (! uk || s1[uk - 1] != s[i])
        {
            s1[uk] = s[i];
            uk++;
        }
        else
            uk--;
    }
    for (i = 0; i < uk; i++)
    {
        cout << s1[i];
    }

    return 0;
}
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int R, D, U, L;

int main()
{
   string s;
    int kol = 0, i, res = 0;
    getline(cin, s);
    while(s != "")
    {
        if (s[0] == '+')
            kol++;
        else
        if (s[0] == '-')
            kol--;
        else
        {
            i = 0;
            while (s[i] != ':')
                i++;
            res += (s.length() - i - 1) * kol;
        }
        getline(cin, s);
    }

    cout << res;

    return 0;
}
#include <iostream>

using namespace std;
string s;
int main()
{
    int n, i;
    bool check;
    cin >> s;
    n = s.length();
    check = true;
    for (i = 1; i < n; i++)
        if (!(s[i] >= 'A' && s[i] <= 'Z'))
            check = false;
    if (check)
    {
        for (i = 0; i < n; i++)
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - 'a' + 'A';
            else
                s[i] = s[i] - 'A' + 'a';
    }
    cout << s;



    return 0;
}
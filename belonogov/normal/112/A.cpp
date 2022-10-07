#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int i;
    for (i = 0; i < s1.length(); i++)
        if (s1[i] < 'a' || s1[i] > 'z')
            s1[i] = s1[i] - 'A' + 'a';

    for (i = 0; i < s2.length(); i++)
        if (s2[i] < 'a' || s2[i] > 'z')
            s2[i] = s2[i] - 'A' + 'a';

    if (s1 < s2)
    {
        cout << -1;
    }
    else
    {
        if (s1 == s2)
            cout << 0;
        else
            cout << 1;
    }
}
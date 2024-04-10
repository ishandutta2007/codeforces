#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s, s1;
    int n, i;
    cin >> s;
    n = s.length();
    for (i = 0; i < n; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
    for (i = 0; i < n; i++)
        if (s[i] != 'a' && s[i] != 'o' && s[i] != 'y'
        && s[i] != 'e' && s[i] != 'u' && s[i] != 'i')
            s1 += s[i];
    n = s1.length();
    for (i = 0; i < n; i++)
        cout << "." << s1[i];
    return 0;
}
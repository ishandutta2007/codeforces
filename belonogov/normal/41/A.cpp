#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;


int main()
{
    int i, n, n1;
    string s, s1;
    cin >> s;
    cin >> s1;
    n = s.length();
    n1 = s1.length();
    if (n != n1)
    {
        cout << "NO";
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        if (s[i] != s1[n - i - 1])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}
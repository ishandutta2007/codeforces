#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
    int i, n, last1 = -1, last0 = -1;
    string s;
    cin >> s;
    n = s.length();
    for (i = 0; i < n; i++)
    {
        if (s[i] == '1')
            last1 = i;
        else
            last0 = i;
        if (i - last0 == 7 || i - last1 == 7)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}
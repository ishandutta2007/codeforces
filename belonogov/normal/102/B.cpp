#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, i, count = 0, x;
    string s;
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++)
        count += (s[i] - '0');
    i = 0;
    if (n > 1)
        i = 1;
    while (count > 9)
    {
        x = count;
        count = 0;
        while (x != 0)
        {
            count += x % 10;
            x /= 10;
        }
        i++;
    }
    cout << i;
    return 0;
}
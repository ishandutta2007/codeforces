#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
   string s;
    int k, a, b, i, j, x, y, n;
    cin >> k >> a >> b;
    cin >> s;
    n = s.length();
    if (k * a > n || k * b < n)
    {
        cout << "No solution";
        return 0;
    }
    x = n - k * a;
    y = x / (b - a);
    for (i = 0; i < y; i++)
    {
        for (j = 0; j < b; j++)
            cout << s[i * b + j];
        cout << "\n";
    }
    for (i = y; i < k - 1; i++)
    {
        for (j = 0; j < a; j++)
            cout << s[b * y + j + (i - y) * a];
        cout << "\n";
    }
    if (n != b * k)
        for (i = b * y + (k - y - 1) * a; i < n; i++)
            cout << s[i];

    return 0;
}
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int R, D, U, L;

int main()
{
    char ch1, ch2;
    int x1, x2, y1, y2;
    scanf("%c%d\n", &ch1, &x1);
    scanf("%c%d", &ch2, &x2);
    y1 = ch1 - 'a' + 1;
    y2 = ch2 - 'a' + 1;
    if (y1 < y2)
        R = y2 - y1;
    else
        L = y1 - y2;
    if (x1 < x2)
        U = x2 - x1;
    else
        D = x1 - x2;
    cout << max(max(R, L), max (U, D)) << "\n";
    while (R != 0 || L != 0 || U != 0 || D != 0)
    {
        if (R > 0)
        {
             cout << "R";
             R--;
        }
        if (L > 0)
        {
             cout << "L";
             L--;
        }
        if (D > 0)
        {
             cout << "D";
             D--;
        }
        if (U > 0)
        {
             cout << "U";
             U--;
        }
        cout << "\n";
    }
    return 0;
}
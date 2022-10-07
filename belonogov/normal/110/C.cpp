#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, kol7, kol4 = 0, k, j;
    cin >> n;
    kol7 = (n + 6) / 7;
    while (kol7 >= 0)
    {
        k = kol7 * 7 + kol4 * 4;
        if (k == n)
        {
            for (j = 0; j < kol4; j++)
                cout << 4;
            for (j = 0; j < kol7; j++)
                cout << 7;
            return 0;
        }
        kol7--;
        k = kol7 * 7 + kol4 * 4;
        if (k < n)
            kol4++;
        k = kol7 * 7 + kol4 * 4;
        if (k < n)
            kol4++;
    }
    cout << -1;
    return 0;
}
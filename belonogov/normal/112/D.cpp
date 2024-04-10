#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
const int MAXX = 1e5 + 10;


int main()
{
    int count, n1, n, i, j, x, y, j1;
    int a[MAXX];
    for (i = 0; i < MAXX; i++)
        a[i] = 0;

    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x >> y;
        n1 = sqrt(x);
        count = 0;
        for (j = 1; j <= n1; j++)
            if (x % j == 0)
            {
                if (a[j] < i - y)
                    count++;
                a[j] = i;

                j1 = x / j;
                if (a[j1] < i - y)
                    count++;
                a[j1] = i;


            }
        cout << count << "\n";
    }
    return 0;
}
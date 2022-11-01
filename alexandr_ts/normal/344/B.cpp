#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int mm, a, b, c, d, e, f;
    cin >> a >> b >> c;
    mm = a;
    if (b > mm)
        mm = b;
    if (c > mm)
        mm = c;
    if ((a + b + c - mm < mm) || (a + b + c) % 2 == 1)
        cout << "Impossible";
    else
    {
        d = 0;
        e = 0;
        f = 0;
        while(a + b + c > 0)
            if (a >= c && b >= c)
            {
                d++;
                a--;
                b--;
            }
            else
                if (a >= b && c >= b)
                {
                    f++;
                    a--;
                    c--;
                }
                else
                {
                    e++;
                    b--;
                    c--;
                }
        cout << d << " " << e << " " << f;
    }

    return 0;
}
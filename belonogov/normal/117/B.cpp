#include <iostream>
#include <cstdio>

using namespace std;
const long long p = 1e9;


int main()
{
     long long a, b, mod, res = 0, kol, d1, i;
    cin >> a >> b >> mod;
    if (mod <= b + 1)
    {
        cout << 2;
        return 0;
    }


    while(res < a && res <= mod)
    {
        res++;
        if ((p * res) % mod + b < mod && (p * res) % mod != 0)
        {
            cout << 1 << " ";
            d1 = res;
            kol = 0;
            while (d1 > 0)
            {
                kol++;
                d1 /= 10;
            }
            for (i = 0; i < 9 - kol; i++)
                cout << 0;
            cout << res;
            return 0;

        }
    }
    cout << 2;


    return 0;
}
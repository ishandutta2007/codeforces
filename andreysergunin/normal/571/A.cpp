#include <iostream>
#include <math.h>


using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    
    long long a, b, c, l;
    cin >> a >> b >> c >> l;
    long long ans = 0;
    for (long long i = 0; i <= l; i++)
        ans += (i + 1) * (i + 2) / 2;
    for (long long i = 0; i <= l; i++)
    {
        long long aa = a + i;
        if (b + c <= aa)
        {
            long long k = min(l - i, aa - b - c);
            ans -= (k + 1) * (k + 2) / 2;
        }
    }
    
    for (long long i = 0; i <= l; i++)
    {
        long long bb = b + i;
        if (a + c <= bb)
        {
            long long k = min(l - i, bb - a - c);
            ans -= (k + 1) * (k + 2) / 2;
        }
    }
    
    for (long long i = 0; i <= l; i++)
    {
        long long cc = c + i;
        if (a + b <= cc)
        {
            long long k = min(l - i, cc - a - b);
            ans -= (k + 1) * (k + 2) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}
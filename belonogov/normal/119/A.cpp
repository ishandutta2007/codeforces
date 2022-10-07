#include <iostream>
#include <cstdio>

using namespace std;
/*int f(int a, int b)
{
    if (b != 0)
        return f(b, a % b);
    return a;
}
*/
int f(int a, int b)
{
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n, a, b, hod = 0;
    cin >> a >> b >> n;
    while (n != 0)
    {
        if (hod == 0)
            n = n - f(a, n);
        if (hod == 1)
            n = n - f(b, n);
        hod = (hod + 1) % 2;
    }
    cout << (hod + 1) % 2;
    return 0;
}
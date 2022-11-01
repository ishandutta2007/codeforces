#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

typedef long long ll;
typedef long double ld;

int a[1000000];

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int siz = max(abs(a - c), abs(b - d));
    if (a != c && b != d)
        if (abs(a - c) != abs(b - d))
    {
        cout << -1;
        return 0;
    }
    if (a == c)
    {
        cout << a + siz << " " << b << " " << c + siz << " " << d << endl;
        return 0;
    }
    if (b == d)
    {
        cout << a << " " << b + siz << " "  << c << " " << d + siz << endl;
        return 0;
    }
    if (a < c && b < d || a > c && b > d)
        cout << min(a, c) << " " << max(b, d) << " " << max(a, c) << " " << min(b, d) << endl;
    else
        cout << min(a, c) << " " << min(b, d) << " " << max(a, c) << " " << max(b, d) << endl;

    return 0;
}
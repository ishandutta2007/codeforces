#include <cstdio>
#include <iostream>

using namespace std;

int a, b, c, d, e, f;
int x, y;

int main()
{
/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/
    cin >> a >> b >> c >> d >> e >> f;
    x = a * c * e;
    y = b * d * f;
    if (y)
    {
        cout << (x < y? "Ron" : "Hermione") << endl;
        return 0;
    }

    cout << (c == 0 && d > 0 || a == 0 && b > 0 && d > 0? "Ron" : "Hermione") << endl;
    return 0;
}
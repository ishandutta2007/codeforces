#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//vector <int> a;
int a[100000];
int b[100000];

int main()
{
   int x, y;
    cin >> x >> y;
    x = max(x, y);
    x = 7 - x;
    y = 6;
    if (x % 2 == 0 && y % 2 == 0)
    {
        x /= 2;
        y /= 2;
    }
    if (x % 3 == 0 && y % 3 == 0)
    {
        x /= 3;
        y /= 3;
    }
    cout << x << "/" << y;

    return 0;
}
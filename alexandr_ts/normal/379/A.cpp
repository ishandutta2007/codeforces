#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int hours = 0;
    int died = 0;

    while(a > 0)
    {
        hours += a;
        died += a;
        a = 0;
        a += died / b;
        died %= b;
    }
    cout << hours;
    return 0;
}
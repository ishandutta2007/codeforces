#include <iostream>
#include <stdio.h>
#include <math.h>
#include <set>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a, b;
    cin >> a >> b;
    if (a < b)
    {
        cout << -1;
        return 0;
    }
    if (a == b)
    {
        cout << a;
        return 0;
    }
    int k1 = (a - b) / (2 * b);
    double ans1 = (double) (a - b) / (2 * k1);
    int k2 = (a + b) / (2 * b);
    double ans2 = (double) (a + b) / (2 * k2);
    printf("%.9lf", min(ans1, ans2));
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

double l, x, y;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lf%lf%lf", &l, &x, &y);
    printf("%.10lf", l * (x / (x + y)));


    return 0;
}
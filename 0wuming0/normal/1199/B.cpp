#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    double a,b;
    scanf("%lf",&a);
    scanf("%lf",&b);
    printf("%.10lf\n",(a*a+b*b)/2/a-a);
    return 0;
}
/*
1 3 3
5
*/
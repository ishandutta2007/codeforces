#include<stdio.h>
#include<cmath>
using namespace std;
int t, x, x2, y, y2;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d", &x, &y, &x2, &y2);
        if(x == x2)
        {
            printf("%d\n", abs(y2 - y));
        }
        else if(y == y2)
        {
            printf("%d\n", abs(x2 - x));
        }
        else
        {
            printf("%d\n", abs(x2 - x) + abs(y2 - y) + 2);
        }
    }
    return 0;
}
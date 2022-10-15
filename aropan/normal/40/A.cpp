#include <cstdio>
#include <cmath>

using namespace std;

int n, m, x, y;

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d %d", &x, &y);
    
    n = x * x + y * y;
    m = (int)sqrt((double)n);
    
    puts(m * m == n ||  ((m + (int)(0 < x && 0 < y || x < 0 && y < 0)) % 2)? "black" : "white");
    return 0;
}
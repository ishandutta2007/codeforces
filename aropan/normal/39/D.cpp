#include <cstdio>

using namespace std;

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    int x1, y1, z1, x2, y2, z2;
    scanf("%d %d %d %d %d %d", & x1, & y1, & z1, & x2, & y2, & z2);
    puts((x1 == x2 || y1 == y2 || z1 == z2)? "YES" : "NO");
    return 0;
}
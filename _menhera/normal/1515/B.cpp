#pragma GCC target("avx2,popcnt")
#include<bits/stdc++.h>
using namespace std;

bool is_sq(int x)
{
    int y = sqrt(x);
    return y*y==x || (y-1)*(y-1) == x || (y+1)*(y+1) == x;
}
int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int x; scanf("%d", &x);
        if(x%2 == 0 && is_sq(x/2) || x%4==0 && is_sq(x/4)) puts("YES");
        else puts("NO");
    }
}
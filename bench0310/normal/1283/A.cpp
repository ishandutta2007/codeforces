#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int h,m;
        scanf("%d%d",&h,&m);
        printf("%d\n",24*60-(60*h+m));
    }
    return 0;
}
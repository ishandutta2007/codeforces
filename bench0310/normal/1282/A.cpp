#include <bits/stdc++.h>

using namespace std;

int solve(int a,int b,int c,int d)
{
    if(b<=c||d<=a) return 0;
    else if(a<=c&&d<=b) return d-c;
    else if(c<=a&&b<=d) return b-a;
    else if(a<=c) return b-c;
    else return d-a;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,r;
        scanf("%d%d%d%d",&a,&b,&c,&r);
        if(a>b) swap(a,b);
        printf("%d\n",b-a-solve(a,b,c-r,c+r));
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int x,y,x1,y1,x2,y2;
        scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);
        bool ok=1;
        x+=(b-a);
        y+=(d-c);
        if(!(x1<=x&&x<=x2)) ok=0;
        if(!(y1<=y&&y<=y2)) ok=0;
        if(a==b&&a!=0&&x1==x&&x==x2) ok=0;
        if(c==d&&c!=0&&y1==y&&y==y2) ok=0;
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
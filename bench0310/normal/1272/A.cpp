#include <bits/stdc++.h>

using namespace std;

int ab(int a)
{
    if(a>=0) return a;
    else return -a;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int res=2000000000;
        for(int o=-1;o<=1;o++) for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++) res=min(res,ab(a+o-b-i)+ab(a+o-c-j)+ab(b+i-c-j));
        printf("%d\n",res);
    }
    return 0;
}
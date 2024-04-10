#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==0&&c==0)
        {
            printf("0");
            for(int i=1;i<=b;i++) printf("%d",(i&1));
        }
        else if(a>0&&c>0)
        {
            printf("0");
            for(int i=0;i<a;i++) printf("0");
            printf("1");
            for(int i=0;i<c;i++) printf("1");
            for(int i=0;i<b-1;i++) printf("%d",(i&1));
        }
        else if(a>0)
        {
            printf("0");
            for(int i=0;i<a;i++) printf("0");
            for(int i=1;i<=b;i++) printf("%d",(i&1));
        }
        else if(c>0)
        {
            printf("1");
            for(int i=0;i<c;i++) printf("1");
            for(int i=0;i<b;i++) printf("%d",(i&1));
        }
        printf("\n");
    }
    return 0;
}
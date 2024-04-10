#include <cstdio>

using namespace std;

inline int cmmdc(int a,int b)
{
    int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

inline int maxim(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int main()
{
    int n,i,v[105],maximul,cmm;
    scanf("%d",&n);
    scanf("%d",&v[0]);
    cmm=v[0];
    maximul=v[0];

    for(i=1;i<n;i++)
    {
        scanf("%d",&v[i]);
        maximul=maxim(maximul,v[i]);
        cmm=cmmdc(cmm,v[i]);
    }
    maximul/=cmm;
    maximul-=n;
    if((maximul%2)==0)
        printf("Bob\n");
    else
        printf("Alice\n");
    return 0;
}
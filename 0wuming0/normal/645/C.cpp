#include"stdio.h"
int n,k,i;
int x1,x2,x;
char a[100001];
int t;
int n1,n2,nn;
int ok(int t1,int t2)
{
    t1=t1>0?t1:0;
    t2=t2>=n?n-1:t2;
    for(i=t1;i<=t2;i++)if(a[i]=='0')return 1;
    return 0;
}
void solve()
{
    if(x1+1==x2)return;
    x=(x1+x2)/2;
    n1=nn=0;
    while(a[n1]=='1')n1++;
    n2=n1;
    while(1)
    {
        n2++;
        if(a[n2]=='0')
        {
            nn++;
            if(nn==k)break;
        }
    }
    while(1)
    {//printf("%d,%d,%d\n",n1,n2,x);
        if(a[n2]==0)
        {
            x1=x;
            break;
        }//printf("123");
        if(ok(n2-x,n1+x))
        {
            x2=x;
            break;
        }
        n1++;
        while(a[n1]=='1')n1++;
        n2++;
        while(a[n2]=='1')n2++;
    }
    solve();
}
int main()
{

    scanf("%d",&n);
    scanf("%d%*c",&k);
    gets(a);

    //n=100000;
    //k=4;
    //for(i=0;i<n;i++)a[i]='0'+i%2;

    x1=0;
    x2=n-1;
    solve();
    printf("%d\n",x2);
    return 0;
}
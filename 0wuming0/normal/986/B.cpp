#include"bits/stdc++.h"
using namespace std;
int a[1000007];
int b[500007];
int c[500007];
int so(int i,int j)
{
    if(i==j)return 0;
    int m=(i+j)/2;
    int ans=so(i,m)+so(m+1,j);
    ans%=2;
    int bn=m-i+1;
    int cn=j-(m+1)+1;
    int *p=a+i;
    for(int i=0;i<bn;i++)b[i]=p[i];
    p=a+m+1;
    for(int i=0;i<cn;i++)c[i]=p[i];
    p=a+i;
    int n=bn+cn;
    for(int i=0,bi=0,ci=0;i<n;i++)
    {
        if(bi==bn)
        {
            p[i]=c[ci];
            ci++;
            if((bn-bi)%2)ans^=1;
        }
        else if(ci==cn)
        {
            p[i]=b[bi];
            bi++;
        }
        else if(b[bi]<c[ci])
        {
            p[i]=b[bi];
            bi++;
        }
        else
        {
            p[i]=c[ci];
            ci++;
            if((bn-bi)%2)ans^=1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",a+i);
    if((n+so(0,n-1))%2==0)cout<<"Petr"<<endl;
    else cout<<"Um_nik"<<endl;
    return 0;
}
/*
5
4 2 1 3 5
*/
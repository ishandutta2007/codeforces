#include"bits/stdc++.h"
#define ll long long
using namespace std;
int a[200005];
int n,an=1;
int index(int p)
{
    int x1=0,x2=n,x;
    while(x1+1!=x2)
    {
        x=(x1+x2)/2;
        if(a[x]>p)x2=x;
        else x1=x;
    }
    return x2;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    sort(a,a+n);

    int i;
    for(i=1;i<n;i++)
        if(a[i]!=a[an-1])
            a[an]=a[i],an++;
    if(an==1)
    {
        cout<<0<<endl;
        return 0;
    }
    n=an;
    int m=0;
    /*
    int t=max(n,103),m=0;
    for(int i=0;i<t;i++)for(int j=i+1;j<n;j++)
        m=max(m,a[j]%a[i]);
    *///cout<<"ok";
    for(int i=n-2;i>=0&&a[i]>m+1;i--)
    {
        m=max(m,a[index(2*a[i]-1)-1]%a[i]);
        for(int j=index(2*a[i]+m);j<n;j++)
        {
            m=max(m,a[j]%a[i]);
        }
    }
    cout<<m<<endl;
    return 0;
}
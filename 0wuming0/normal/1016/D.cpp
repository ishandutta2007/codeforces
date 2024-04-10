#include"bits/stdc++.h"
using namespace std;
int n,m;
int a[105],b[105],ans[105][105];
int main()
{
    cin>>n>>m;int sum=0,as;
    for(int i=0;i<n;i++)scanf("%d",a+i),sum^=a[i];as=sum;
    for(int i=0;i<m;i++)scanf("%d",b+i),sum^=b[i];
    if(sum==0)
    {
        cout<<"YES"<<endl;
        as^=a[0];as^=b[0];
        cout<<as;
        for(int i=1;i<m;i++)printf(" %d",b[i]);cout<<endl;
        for(int j=1;j<n;j++)
        {
            printf("%d",a[j]);
            for(int i=1;i<m;i++)printf(" 0");
            putchar(10);
        }
    }
    else cout<<"NO"<<endl;
    return 0;
}
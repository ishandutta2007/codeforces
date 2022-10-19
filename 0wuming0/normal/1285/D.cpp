#include"bits/stdc++.h"
using namespace std;
int solve(int a[],int n,int bb)
{
    if(bb==-1)return 0;
    int n1=0,t=(1<<bb);
    sort(a,a+n);
    while(n1!=n&&(a[n1]&t)==0)n1++;
    for(int i=n1;i<n;i++)a[i]^=t;
    if(n1==0||n1==n)return solve(a,n,bb-1);
    else return t^min(solve(a,n1,bb-1),solve(a+n1,n-n1,bb-1));
}
int a[100006];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    cout<<solve(a,n,29)<<endl;
    return 0;
}
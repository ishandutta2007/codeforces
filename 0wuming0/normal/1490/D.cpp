#include"bits/stdc++.h"
using namespace std;
void solve(int a[],int n,int now)
{
    if(n==0)return;
    int m=-1,pos;
    for(int i=0;i<n;i++)if(a[i]>m)m=a[pos=i];
    a[pos]=now;
    solve(a,pos,now+1);
    solve(a+pos+1,n-pos-1,now+1);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a[105];
        int n;
        cin>>n;
        for(int i=0;i<n;i++)scanf("%d",a+i);
        solve(a,n,0);
        for(int i=0;i<n;i++)printf("%d%c",a[i]," \n"[i==n-1]);
    }
    return 0;
}
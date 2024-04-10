#include"bits/stdc++.h"
using namespace std;
int a[200005],b[200005];
int n;
int solve(int x)
{
    int now=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]+1+now>=x&&now<=a[i])
        {
            now++;
        }
    }
    if(now>=x)return 1;
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)scanf("%d%d",b+i,a+i);
        int l=1,r=n+1;
        while(l+1!=r)
        {
            int x=l+r>>1;
            if(solve(x))l=x;
            else r=x;
        }
        cout<<l<<endl;
    }
    return 0;
}
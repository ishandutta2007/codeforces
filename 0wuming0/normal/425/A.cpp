#include"bits/stdc++.h"
using namespace std;
int a[205];
int save1[205],n1,save2[205],n2;
int n,k;
int solve(int l,int r)
{
    n1=0;
    int ans=0;
    for(int i=l;i<=r;i++)
    {
        ans+=a[i];
        save1[n1]=a[i];
        n1++;
    }
    n2=0;
    for(int i=0;i<l;i++)
    {
        save2[n2]=a[i];
        n2++;
    }
    for(int i=r+1;i<n;i++)
    {
        save2[n2]=a[i];
        n2++;
    }
    sort(save1,save1+n1);
    sort(save2,save2+n2);
    int now=k;
    for(int i=0,j=n2-1;;i++,j--)
    {
        if(now==0||j<0||i>=n1)break;
        if(save1[i]<save2[j])
        {
            ans+=save2[j]-save1[i];
            now--;
        }
        else break;
    }
    return ans;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    int ans=-1e9;
    for(int i=0;i<n;i++)for(int j=i;j<n;j++)
    {
        ans=max(solve(i,j),ans);
    }
    cout<<ans<<endl;
    return 0;
}
/*
3 21
-1 -5 -3
*/
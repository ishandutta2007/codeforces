#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[4005],b[4005];
int solve(int a,int b,int c,int d)
{
    if(b<c||d<a)return 0;
    a=max(a,c);
    b=min(b,d);
    return b-a+1;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)scanf("%d%d",a+i,b+i);
    int best=0;
    for(int i=1;i<=2000;i++)
    {
        int ans=0;
        int s[2005]={0};
        for(int j=0;j<m;j++)
        {
            int add=solve(a[j],b[j],i,i+k-1);
            ans+=add;
            //a[j] b[j]
            if(add==k)continue;
            else if(add==b[j]-a[j]+1)continue;
            else
            {
                if(b[j]-add>=0)s[b[j]-add]++;
                if(a[j]-1>=0)s[a[j]-1]--;
                k++;
                if(b[j]-k+1>=0)s[b[j]-k+1]--;
                if(a[j]-add-k>=0)s[a[j]-add-k]++;
                k--;
            }
        }
        for(int j=2004;j>0;j--)s[j-1]+=s[j];
        for(int j=2004;j>0;j--)s[j-1]+=s[j];
        for(int j=0;j<2004;j++)s[0]=max(s[j],s[0]);
        ans+=s[0];
        best=max(best,ans);
    }
    cout<<best<<endl;
    return 0;
}
#include"bits/stdc++.h"
using namespace std;
int n,k;
int a[200005];
int s[200005];
int solve(int x)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]>=x)s[i]=1;
        else s[i]=0;
    }
    int l=0,r=0,now=s[0];
    int last=0;
    while(1)
    {
        if(r==n)return 0;
        else if(r-l+1<k)
        {
            r++;
            now+=s[r];
        }
        else if(now*2+last>r-l+1)
        {
            return 1;
        }
        else
        {
            now-=s[l];
            if(s[l]==0)last--;
            else last++;
            if(last<0)last=0;
            l++;
        }
    }
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)scanf("%d",a+i);
    int x1=1,x2=3e5,x;
    while(x1+1!=x2)
    {
        x=(x1+x2)/2;
        if(solve(x))x1=x;
        else x2=x;
    }
    cout<<x1<<endl;
    return 0;
}
/*
1 1
100
*/
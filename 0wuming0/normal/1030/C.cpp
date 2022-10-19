#include"bits/stdc++.h"
using namespace std;
char s[105];int n;
int judge(int i)
{
    int sum=0,nn=0;
    for(int k=0;k<n;k++)
    {
        sum+=s[k];
        if(sum>i)return 0;
        if(sum==i)sum=0;
    }
    if(sum==0)return 1;
    return 0;
}
int main()
{
    cin>>n;
    scanf("%s",s);
    for(int i=0;i<n;i++)s[i]-='0';
    int sum=0,flag=0;
    for(int i=0;i<n;i++)sum+=s[i];
    for(int i=2;i<sum;i++)
    {
        if(sum%i==0)
        {
            if(judge(i)){flag=1;break;}
        }
    }
    int i;
    for(i=0;i<n;i++)if(s[i]!=0)break;
    if(i==n)flag=1;
    sum=0;
    for(i=0;i<n;i++)if(s[i]!=0&&s[i]!=1){break;}else if(s[i]==1)sum++;
    if(i==n&&sum>=2)flag=1;
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
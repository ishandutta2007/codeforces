#include"bits/stdc++.h"
using namespace std;
int main()
{
    char s[105][105];int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]);
    }
    scanf("%s",s[0]);
    int t=0;
    for(int i=1;i<=n;i++)
    {
        if(strcmp(s[0],s[i])==0)t++;
    }
    int len=strlen(s[0]),t0=0,t1=0;
    for(int i=1;i<=n;i++)
        if(strlen(s[i])<=len)t0++;
    for(int i=1;i<=n;i++)
        if(strlen(s[i])<len)t1++;
    t0-=t;
    cout<<t1/k*5+t1+1<<" "<<t0/k*5+t0+1<<endl;
    return 0;
}
#include"bits/stdc++.h"
using namespace std;
char s[300005];
int m[300005];
int sum[300005];
int main()
{
    int n,k;
    cin>>n>>k;
    scanf("%s",s);
    int i;
    for(i=300004;i>=0;i--)
    {
        m[i]=-1;
        if(s[i]=='#')break;
    }
    int now=i;
    for(;i>=0;i--)
    {
        if(s[i]=='#')now=i;
        m[i]=now;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='#')sum[i]++;
        if(i>0)sum[i]+=sum[i-1];
    }
    for(int i=0;;)
    {
        if(m[i]==-1)
        {
            cout<<"YES"<<endl;
            return 0;
        }
        for(int j=1;j<=k;j++)
        {
            if(s[i+j]!='#')
            {
                i=i+j;
                break;
            }
            if(j==k)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    return 0;
}
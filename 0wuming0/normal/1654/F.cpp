#include"bits/stdc++.h"
using namespace std;
char s[300006];
int dp[300006];
int pos[300006];
int temp[300006];
int cmpk;
bool cmp(int x,int y)
{
    if(dp[x]==dp[y])return dp[x^cmpk]<dp[y^cmpk];
    return dp[x]<dp[y];
}
int main()
{
    int n;
    cin>>n;
    cin>>s;
    for(int i=0;s[i];i++)
    {
        dp[i]=s[i]-'a';
        pos[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        cmpk=(1<<i);
        for(int i=0;i<(1<<n);i++)pos[i]=i;
        sort(pos,pos+(1<<n),cmp);
        int now=0;
        for(int l=0,r=0;r<(1<<n);r++)
        {
            if(cmp(pos[l],pos[r])!=cmp(pos[r],pos[l]))
            {
                temp[r]=++now;
                l=r;
            }
            else temp[r]=now;
        }
        for(int i=0;i<(1<<n);i++)
        {
            dp[pos[i]]=temp[i];
        }
    }
    for(int i=0;i<(1<<n);i++)putchar(s[i^pos[0]]);
    cout<<endl;
    return 0;
}
#include"bits/stdc++.h"
using namespace std;
int main()
{
    char m[10][10];
    for(int i=0;i<8;i++)
        scanf("%s",m[i]);
        int i,j;int n=8;
    for(i=0;i<n;i++)for(j=0;j<n;j++)
    {
        if(m[i][j]=='W')goto ee;
    }ee:
    if(i==n)cout<<8<<endl;
    else
    {
        int ans=0;
        for(int k=0;k<8;k++)
        {
            if(m[i][k]=='B')ans++;
            if(m[k][j]=='B')ans++;
        }cout<<ans<<endl;
    }
    return 0;
}
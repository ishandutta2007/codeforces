#include"bits/stdc++.h"
using namespace std;
char s[1005][1005];
int n,m;
int no()
{
    cout<<-1<<endl;
    exit(0);
}
int solve(int i,int j)
{
    if(i<0)return 0;
    if(j<0)return 0;
    if(i>=n)return 0;
    if(j>=m)return 0;
    if(s[i][j]!='#')return 0;
    s[i][j]='.';
    solve(i+1,j);
    solve(i,j+1);
    solve(i-1,j);
    solve(i,j-1);
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)scanf("%s",s[i]);
    for(int i=0;i<n;i++)
    {
        int flag=1;
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='#')
            {
                if(flag==0)no();
                while(s[i][j]=='#')j++;
                flag=0;
            }
        }
        if(flag)
        {
            for(int j=0;j<m;j++)
            {
                for(int ii=0;ii<n;ii++)
                {
                    if(s[ii][j]=='#')break;
                    if(ii==n-1)goto nexts2;
                }
            }no();
        }

        nexts2:;
    }
    for(int i=0;i<1003;i++)for(int j=i+1;j<1003;j++)
        swap(s[i][j],s[j][i]);
    swap(n,m);
    for(int i=0;i<n;i++)
    {
        int flag=1;
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='#')
            {
                if(flag==0)no();
                while(s[i][j]=='#')j++;
                flag=0;
            }
        }
        if(flag)
        {
            for(int j=0;j<m;j++)
            {
                for(int ii=0;ii<n;ii++)
                {
                    if(s[ii][j]=='#')break;
                    if(ii==n-1)goto nexts;
                }
            }no();
        }

        nexts:;
    }
    int ans=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {//cout<<"ok"<<endl;
        if(s[i][j]=='#')ans++,solve(i,j);
    }
    cout<<ans<<endl;
    return 0;
}
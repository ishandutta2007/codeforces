#include"bits/stdc++.h"
using namespace std;
char mp[100][100];
int ok[20][20];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ok[i][j]=0;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        {
            int l=0,r=0;
            while(1)
            {
                int x=i-r;
                int y=j+r;
                if(x<1||y>m||y<1||mp[x][y]!='*')break;
                r++;
            }
            while(1)
            {
                int x=i-l;
                int y=j-l;
                if(x<1||y>m||y<1||mp[x][y]!='*')break;
                l++;
            }l--;r--;
            l=r=min(l,r);if(l>=k)
            for(int k=0;k<=l;k++)
            {
                ok[i-k][j+k]=1;
                ok[i-k][j-k]=1;
            }
        }
        bool f=1;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(mp[i][j]=='*'&&ok[i][j]!=1)f=0;
        if(f)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
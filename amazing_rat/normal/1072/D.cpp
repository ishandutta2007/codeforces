#include<bits/stdc++.h>

using namespace std;

const int maxn=2010;

char s[maxn][maxn];
int v[maxn][maxn];
int d[maxn][maxn];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    
    memset(d,0,sizeof d);
    
	int ma=0;
    
	for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>1&&j>1)d[i][j]=min(d[i-1][j],d[i][j-1]);
            else if(i>1)d[i][j]=d[i-1][j];
            else if(j>1)d[i][j]=d[i][j-1];
            d[i][j]+=(s[i][j]!='a');
            if(d[i][j]<=m)ma=max(ma,i+j-1);
        }
    }
    
	queue<int>p,q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(d[i][j]<=m&&i+j-1==ma)
            {
                p.push(i);
                p.push(j);
            }
        }
    }
    string ans="";
    for(int i=1;i<=ma;i++)ans+='a';
    if(ma==0)
    {
        p.push(1);
        p.push(1);
        ans+=s[1][1];
        ma++;
    }
    for(int i=ma+1;i<=2*n-1;i++)
    {
        q=p;
        char nex='z';
        while(!p.empty())
        {
            int x=p.front();p.pop();
            int y=p.front();p.pop();
            if(x+1<=n)nex=min(nex,s[x+1][y]);
            if(y+1<=n)nex=min(nex,s[x][y+1]);
        }
        ans+=nex;

        while(!q.empty())
        {
            int x=q.front();q.pop();
            int y=q.front();q.pop();
            if(x+1<=n&&s[x+1][y]==nex&&v[x+1][y]==0)
            {
                p.push(x+1);
                p.push(y);
                v[x+1][y]=1;
            }
            if(y+1<=n&&s[x][y+1]==nex&&v[x][y+1]==0)
            {
                p.push(x);
                p.push(y+1);
                v[x][y+1]=1;
            }
        }
    }
	printf("%s\n",ans.c_str()) ;
    return 0;
}
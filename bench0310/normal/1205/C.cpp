#include <bits/stdc++.h>

using namespace std;

const int N=55;
int n;
int res[N][N];
int dp[N][N][N][N][2];

bool query(int a,int b,int c,int d)
{
    printf("? %d %d %d %d\n",a,b,c,d);
    fflush(stdout);
    int t;
    scanf("%d",&t);
    return t;
}

void ans()
{
    printf("!\n");
    for(int o=1;o<=n;o++)
    {
        for(int i=1;i<=n;i++) printf("%d",res[o][i]);
        printf("\n");
    }
    fflush(stdout);
    exit(0);
}

bool in(int r,int c)
{
    return (1<=min(r,c)&&max(r,c)<=n);
}

void invert()
{
    for(int o=1;o<=n;o++)
    {
        for(int i=1;i<=n;i++)
        {
            if((o+i)&1) res[o][i]=1-res[o][i];
        }
    }
}

int solve(int a,int b,int c,int d,int t)
{
    int &now=dp[a][b][c][d][t];
    if(now!=-1) return now;
    if(a>c||b>d) return now=0;
    if(res[a][b]!=res[c][d]) return now=0;
    if((c-a)+(d-b)<=1) return now=(res[a][b]==res[c][d]);
    if(solve(a+1,b,c-1,d,t)||solve(a+1,b,c,d-1,t)||solve(a,b+1,c-1,d,t)||solve(a,b+1,c,d-1,t)) return now=1;
    else return now=0;
}

int main()
{
	scanf("%d",&n);
	memset(res,-1,sizeof res);
	memset(dp,-1,sizeof dp);
	res[1][1]=res[1][2]=1;
	res[n][n]=0;
	int z[3][2]={{-2,0},{-1,-1},{0,-2}};
	for(int o=1;o<=n;o++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(res[o][i]!=-1) break;
                int r=o+z[j][0];
                int c=i+z[j][1];
                if(in(r,c)&&res[r][c]!=-1) res[o][i]=(res[r][c]+query(r,c,o,i)+1)%2;
            }
        }
    }
    for(int o=2;o<=n;o+=2) res[o][1]=(res[o+1][2]+query(o,1,o+1,2)+1)%2;
    for(int a=1;a<=n;a++) for(int b=1;b<=n;b++) for(int c=a;c<=n;c++) for(int d=b;d<=n;d++) solve(a,b,c,d,0);
    invert();
    for(int a=1;a<=n;a++) for(int b=1;b<=n;b++) for(int c=a;c<=n;c++) for(int d=b;d<=n;d++) solve(a,b,c,d,1);
    for(int a=1;a<=n;a++)
    {
        for(int b=1;b<=n;b++)
        {
            for(int c=a;c<=n;c++)
            {
                for(int d=b;d<=n;d++)
                {
                    if((c-a)+(d-b)<=1) continue;
                    if(dp[a][b][c][d][0]!=dp[a][b][c][d][1])
                    {
                        if(query(a,b,c,d)==dp[a][b][c][d][0]) invert();
                        ans();
                    }
                }
            }
        }
    }
	return 0;
}
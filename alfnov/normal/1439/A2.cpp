#include<bits/stdc++.h>
using namespace std;
int n,m,tot,a[105][105];
int q1x[10005],q2x[10005],q3x[10005];
int q1y[10005],q2y[10005],q3y[10005];
int s[5][2]={{0,0},{1,1},{1,0},{0,1},{0,0}};
char ff[10005];
void qwq(int t1,int t2,int t3)
{
	tot++;
	q1x[tot]=n-s[t1][0],q1y[tot]=m-s[t1][1];
	q2x[tot]=n-s[t2][0],q2y[tot]=m-s[t2][1];
	q3x[tot]=n-s[t3][0],q3y[tot]=m-s[t3][1];
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		tot=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",ff+1);
			for(int j=1;j<=m;j++)a[i][j]=ff[j]-'0';
		}
		for(int i=1;i<=n-2;i++)
		{
			for(int j=1;j<m;j++)if(a[i][j])
			{
				tot++;
				q1x[tot]=i,q1y[tot]=j;
				q2x[tot]=i+1,q2y[tot]=j;
				q3x[tot]=i+1,q3y[tot]=j+1;
				a[i][j]^=1,a[i+1][j]^=1,a[i+1][j+1]^=1; 
			}
			if(a[i][m])
			{
				tot++;
				int j=m;
				q1x[tot]=i,q1y[tot]=j;
				q2x[tot]=i+1,q2y[tot]=j;
				q3x[tot]=i+1,q3y[tot]=j-1;
				a[i][j]^=1,a[i+1][j]^=1,a[i+1][j-1]^=1;
			}
		}
		for(int i=1;i<=m-2;i++)
		{
			if(a[n-1][i])
			{
				tot++;
				q1x[tot]=n-1,q1y[tot]=i;
				q2x[tot]=n-1,q2y[tot]=i+1;
				q3x[tot]=n,q3y[tot]=i+1;
				a[n-1][i]^=1,a[n-1][i+1]^=1,a[n][i+1]^=1;
			}
			if(a[n][i])
			{
				tot++;
				q1x[tot]=n,q1y[tot]=i;
				q2x[tot]=n,q2y[tot]=i+1;
				q3x[tot]=n-1,q3y[tot]=i+1;
				a[n][i]^=1,a[n][i+1]^=1,a[n-1][i+1]^=1;
			}
		}
		int a1=a[n-1][m-1],a2=a[n-1][m],a3=a[n][m-1],a4=a[n][m];
		if(a1==0&&a2==0&&a3==0&&a4==0)
		{
			
		}else if(a1==0&&a2==0&&a3==0&&a4==1)
		{
			qwq(2,3,4);
			qwq(1,3,4);
			qwq(1,2,4);
		}else if(a1==0&&a2==0&&a3==1&&a4==0)
		{
			qwq(2,3,4);
			qwq(1,3,4);
			qwq(1,2,3);
		}else if(a1==0&&a2==0&&a3==1&&a4==1)
		{
			qwq(1,2,3);
			qwq(1,2,4);
		}else if(a1==0&&a2==1&&a3==0&&a4==0)
		{
			qwq(2,3,4);
			qwq(1,2,4);
			qwq(1,2,3);
		}else if(a1==0&&a2==1&&a3==0&&a4==1)
		{
			qwq(1,3,4);
			qwq(1,2,3);
		}else if(a1==0&&a2==1&&a3==1&&a4==0)
		{
			qwq(1,2,4);
			qwq(1,3,4);
		}else if(a1==0&&a2==1&&a3==1&&a4==1)
		{
			qwq(2,3,4); 
		}else if(a1==1&&a2==0&&a3==0&&a4==0)
		{
			qwq(1,2,4);
			qwq(1,2,3);
			qwq(1,3,4);
		}else if(a1==1&&a2==0&&a3==0&&a4==1)
		{
			qwq(1,2,3);
			qwq(2,3,4);
		}else if(a1==1&&a2==0&&a3==1&&a4==0)
		{
			qwq(1,2,4);
			qwq(2,3,4);
		}else if(a1==1&&a2==0&&a3==1&&a4==1)
		{
			qwq(1,3,4);
		}else if(a1==1&&a2==1&&a3==0&&a4==0)
		{
			qwq(1,3,4);
			qwq(2,3,4);
		}else if(a1==1&&a2==1&&a3==0&&a4==1)
		{
			qwq(1,2,4);
		}else if(a1==1&&a2==1&&a3==1&&a4==0)
		{
			qwq(1,2,3);
		}else if(a1==1&&a2==1&&a3==1&&a4==1)
		{
			qwq(1,2,3);
			qwq(1,2,4);
			qwq(1,3,4);
			qwq(2,3,4);
		}
		cout<<tot<<endl;
		for(int i=1;i<=tot;i++)
			printf("%d %d %d %d %d %d\n",q1x[i],q1y[i],q2x[i],q2y[i],q3x[i],q3y[i]);
	}
	return 0;
}
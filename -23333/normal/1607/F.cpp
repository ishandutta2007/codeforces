#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=2010;
char a[N][N];
bool ins[N][N],vis[N][N];
int ans[N][N],n,m;
struct re{
	short a,b;
};
re ve[N*N];
int num=0,num2=0;
int cnt=0;short X1,Y1;
void dfs(short x,short y)
{
	ve[++num]={x,y};
	while (1)
	{
		 int x,y;
		 x=ve[num].a,y=ve[num].b;
		 vis[x][y]=1;
		 int X1=x,Y1=y;
		 if (a[x][y]=='R') Y1++;
		 if (a[x][y]=='L') Y1--;
		 if (a[x][y]=='U') X1--;
		 if (a[x][y]=='D') X1++;
		 ins[x][y]=1;
		 if (X1>=1&&X1<=n&&Y1>=1&&Y1<=m)
		 {
		 	if (vis[X1][Y1])
		 	{
		 		if (!ins[X1][Y1])
				{ 
				  ans[x][y]=ans[X1][Y1]+1;
				  dep(i,num-1,1) ans[ve[i].a][ve[i].b]=ans[ve[i+1].a][ve[i+1].b]+1;
		 	      rep(i,1,num) ins[ve[i].a][ve[i].b]=0;
		          return;
				} else
		 		{
		 			num2=num;
		 			while (num>0)
		 			{
		 				if (ve[num].a==X1&&ve[num].b==Y1) break;
		 				num--;
		 			}
		 			rep(i,num,num2)
		 			  ans[ve[i].a][ve[i].b]=num2-num+1;
		 		    dep(i,num-1,1) ans[ve[i].a][ve[i].b]=ans[ve[i+1].a][ve[i+1].b]+1;
		 	        rep(i,1,num2) ins[ve[i].a][ve[i].b]=0;
		            return;
				}
		 	} else
			{ 
			  ve[++num]={X1,Y1};
		    }
		 } else
		 { 
		   ans[x][y]=1;
		   dep(i,num-1,1) ans[ve[i].a][ve[i].b]=ans[ve[i+1].a][ve[i+1].b]+1;
		   rep(i,1,num) ins[ve[i].a][ve[i].b]=0;
		   return;
	     }
	} 
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		rep(i,1,n) cin>>(a[i]+1);
		rep(i,1,n)
		  rep(j,1,m)
		    if (!vis[i][j])
		    {
		      dfs(i,j);
		      num=0;
		    }
		int anss=0,t1=0,t2=0;
		rep(i,1,n)
		  rep(j,1,m)
		    if (ans[i][j]>anss)
			{ 
			  anss=ans[i][j];
			  t1=i;
			  t2=j;
		    }
		cout<<t1<<" "<<t2<<" "<<anss<<endl;
		rep(i,1,n)
		  rep(j,1,m)
		    vis[i][j]=ans[i][j]=0;
    }
	return 0; 
}
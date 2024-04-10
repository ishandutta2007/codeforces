#include<cstdio>
#include<cstring>
int n,l1,l2,Mx,ans_t=0;
bool ok;
char s[8];
int pw[8],idx[8],tim[8],w[200002];
int num[8][8]={},cnt[8][8];
struct aaa
{
	int x,y;
}ans[200002];
inline void swap(int &x,int &y)
{
	int z=x;x=y,y=z;
}
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline bool check()
{
	int r=0;
	for(int i=1;i<=Mx;++i)tim[i]=0;
	for(int i=1;i<=Mx;++i)
		for(int j=i+1;j<=Mx;++j)
			tim[i]+=num[i][j],tim[j]+=num[i][j];
	for(int i=1;i<=Mx;++i)
	{
		if(!tim[i])return 0;
		r+=tim[i];
	}
	if((r>>1)!=Mx-1)return 0;
	return 1;
}
inline void dfs(int x,int y)
{
	if(y==x+1)if(num[x-1][x-1])return ;
	if(y>Mx)
	{
		if(num[x][x])return ;
		if(!check())return ;
		for(int i=1;i<=Mx;++i)
			for(int j=1;j<=Mx;++j)
				if(num[i][j])
					ans[++ans_t]=(aaa){pw[i-1],pw[j-1]};
		return (void)(ok=1);
	}
	int t,t1;
	if(num[x][y]>=num[x][x])//1.buliu - quan >= num[x][x] - quan -> num[x][x] sheng -> num[y][y]
	{
		t=num[x][x],t1=num[x][y]-t;
		if(num[y][y]>=t1)
		{
			num[x][x]-=t,num[y][y]-=t1,num[x][y]-=t+t1;
			if(y==Mx)dfs(x+1,x+2);else dfs(x,y+1);
			if(ok)
			{
				for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
				for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
				return ;
			}
			num[x][x]+=t,num[y][y]+=t1,num[x][y]+=t+t1;
		}
	}
	else//2.buliu - quan < num[x][x] - quan -> num[x][x]
	{
		t=num[x][y],t1=num[x][y]-t;
		if(num[y][y]>=t1)
		{
			num[x][x]-=t,num[y][y]-=t1,num[x][y]-=t+t1;
			if(y==Mx)dfs(x+1,x+2);else dfs(x,y+1);
			if(ok)
			{
				for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
				for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
				return ;
			}
			num[x][x]+=t,num[y][y]+=t1,num[x][y]+=t+t1;
		}
	}
	if(num[x][y]>=num[y][y])//3.buliu - quan >= num[y][y] - quan -> num[y][y] sheng -> num[x][x]
	{
		t=num[y][y],t1=num[x][y]-t;
		if(num[x][x]>=t1)
		{
			num[y][y]-=t,num[x][x]-=t1,num[x][y]-=t+t1;
			if(y==Mx)dfs(x+1,x+2);else dfs(x,y+1);
			if(ok)
			{
				for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
				for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
				return ;
			}
			num[y][y]+=t,num[x][x]+=t1,num[x][y]+=t+t1;
		}
	}
	else//4.buliu - quan < num[y][y] - quan -> num[y][y]
	{
		t=num[x][y],t1=num[x][y]-t;
		if(num[x][x]>=t1)
		{
			num[y][y]-=t,num[x][x]-=t1,num[x][y]-=t+t1;
			if(y==Mx)dfs(x+1,x+2);else dfs(x,y+1);
			if(ok)
			{
				for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
				for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
				return ;
			}
			num[y][y]+=t,num[x][x]+=t1,num[x][y]+=t+t1;
		}
	}
	if(num[x][y])
	{
		if(num[x][y]-1>=num[x][x])//5.liu - quan >= num[x][x] - quan -> num[x][x] sheng -> num[y][y]
		{
			t=num[x][x],t1=num[x][y]-1-t;
			if(num[y][y]>=t1)
			{
				num[x][x]-=t,num[y][y]-=t1,num[x][y]-=t+t1;
				if(y==Mx)dfs(x+1,x+2);else dfs(x,y+1);
				if(ok)
				{
					for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
					for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
					return ;
				}
				num[x][x]+=t,num[y][y]+=t1,num[x][y]+=t+t1;
			}
		}
		else//6.liu - quan < num[x][x] - quan -> num[x][x]
		{
			t=num[x][y]-1,t1=num[x][y]-1-t;
			if(num[y][y]>=t1)
			{
				num[x][x]-=t,num[y][y]-=t1,num[x][y]-=t+t1;
				if(y==Mx)dfs(x+1,x+2);else dfs(x,y+1);
				if(ok)
				{
					for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
					for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
					return ;
				}
				num[x][x]+=t,num[y][y]+=t1,num[x][y]+=t+t1;
			}
		}
		if(num[x][y]-1>=num[y][y])//7.liu - quan >= num[y][y] - quan -> num[y][y] sheng -> num[x][x]
		{
			t=num[y][y],t1=num[x][y]-1-t;
			if(num[x][x]>=t1)
			{
				num[y][y]-=t,num[x][x]-=t1,num[x][y]-=t+t1;
				if(y==Mx)dfs(x+1,x+2);else dfs(x,y+1);
				if(ok)
				{
					for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
					for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
					return ;
				}
				num[y][y]+=t,num[x][x]+=t1,num[x][y]+=t+t1;
			}
		}
		else//8.liu - quan < num[y][y] - quan -> num[y][y]
		{
			t=num[x][y]-1,t1=num[x][y]-1-t;
			if(num[x][x]>=t1)
			{
				num[y][y]-=t,num[x][x]-=t1,num[x][y]-=t+t1;
				if(y==Mx)dfs(x+1,x+2);else dfs(x,y+1);
				if(ok)
				{
					for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
					for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
					return ;
				}
				num[y][y]+=t,num[x][x]+=t1,num[x][y]+=t+t1;
			}
		}
	}
}
inline void dfs1(int x,int y)
{
	if(y==x+1)if(num[y+1][y+1])return ;
	if(!x)
	{
		if(num[y][y])return ;
		if(!check())return ;
		for(int i=1;i<=Mx;++i)
			for(int j=1;j<=Mx;++j)
				if(num[i][j])
					ans[++ans_t]=(aaa){pw[i-1],pw[j-1]};
		return (void)(ok=1);
	}
	int t,t1;
	if(num[x][y]>=num[x][x])//1.buliu - quan >= num[x][x] - quan -> num[x][x] sheng -> num[y][y]
	{
		t=num[x][x],t1=num[x][y]-t;
		if(num[y][y]>=t1)
		{
			num[x][x]-=t,num[y][y]-=t1,num[x][y]-=t+t1;
			if(x==1)dfs1(y-2,y-1);else dfs1(x-1,y);
			if(ok)
			{
				for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
				for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
				return ;
			}
			num[x][x]+=t,num[y][y]+=t1,num[x][y]+=t+t1;
		}
	}
	else//2.buliu - quan < num[x][x] - quan -> num[x][x]
	{
		t=num[x][y],t1=num[x][y]-t;
		if(num[y][y]>=t1)
		{
			num[x][x]-=t,num[y][y]-=t1,num[x][y]-=t+t1;
			if(x==1)dfs1(y-2,y-1);else dfs1(x-1,y);
			if(ok)
			{
				for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
				for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
				return ;
			}
			num[x][x]+=t,num[y][y]+=t1,num[x][y]+=t+t1;
		}
	}
	if(num[x][y]>=num[y][y])//3.buliu - quan >= num[y][y] - quan -> num[y][y] sheng -> num[x][x]
	{
		t=num[y][y],t1=num[x][y]-t;
		if(num[x][x]>=t1)
		{
			num[y][y]-=t,num[x][x]-=t1,num[x][y]-=t+t1;
			if(x==1)dfs1(y-2,y-1);else dfs1(x-1,y);
			if(ok)
			{
				for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
				for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
				return ;
			}
			num[y][y]+=t,num[x][x]+=t1,num[x][y]+=t+t1;
		}
	}
	else//4.buliu - quan < num[y][y] - quan -> num[y][y]
	{
		t=num[x][y],t1=num[x][y]-t;
		if(num[x][x]>=t1)
		{
			num[y][y]-=t,num[x][x]-=t1,num[x][y]-=t+t1;
			if(x==1)dfs1(y-2,y-1);else dfs1(x-1,y);
			if(ok)
			{
				for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
				for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
				return ;
			}
			num[y][y]+=t,num[x][x]+=t1,num[x][y]+=t+t1;
		}
	}
	if(num[x][y])
	{
		if(num[x][y]-1>=num[x][x])//5.liu - quan >= num[x][x] - quan -> num[x][x] sheng -> num[y][y]
		{
			t=num[x][x],t1=num[x][y]-1-t;
			if(num[y][y]>=t1)
			{
				num[x][x]-=t,num[y][y]-=t1,num[x][y]-=t+t1;
				if(x==1)dfs1(y-2,y-1);else dfs1(x-1,y);
				if(ok)
				{
					for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
					for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
					return ;
				}
				num[x][x]+=t,num[y][y]+=t1,num[x][y]+=t+t1;
			}
		}
		else//6.liu - quan < num[x][x] - quan -> num[x][x]
		{
			t=num[x][y]-1,t1=num[x][y]-1-t;
			if(num[y][y]>=t1)
			{
				num[x][x]-=t,num[y][y]-=t1,num[x][y]-=t+t1;
				if(x==1)dfs1(y-2,y-1);else dfs1(x-1,y);
				if(ok)
				{
					for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
					for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
					return ;
				}
				num[x][x]+=t,num[y][y]+=t1,num[x][y]+=t+t1;
			}
		}
		if(num[x][y]-1>=num[y][y])//7.liu - quan >= num[y][y] - quan -> num[y][y] sheng -> num[x][x]
		{
			t=num[y][y],t1=num[x][y]-1-t;
			if(num[x][x]>=t1)
			{
				num[y][y]-=t,num[x][x]-=t1,num[x][y]-=t+t1;
				if(x==1)dfs1(y-2,y-1);else dfs1(x-1,y);
				if(ok)
				{
					for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
					for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
					return ;
				}
				num[y][y]+=t,num[x][x]+=t1,num[x][y]+=t+t1;
			}
		}
		else//8.liu - quan < num[y][y] - quan -> num[y][y]
		{
			t=num[x][y]-1,t1=num[x][y]-1-t;
			if(num[x][x]>=t1)
			{
				num[y][y]-=t,num[x][x]-=t1,num[x][y]-=t+t1;
				if(x==1)dfs1(y-2,y-1);else dfs1(x-1,y);
				if(ok)
				{
					for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
					for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
					return ;
				}
				num[y][y]+=t,num[x][x]+=t1,num[x][y]+=t+t1;
			}
		}
	}
}
inline void dfs2(int x,int y)
{
	if(y==Mx)if(num[x-1][x-1])return ;
	if(x==Mx)
	{
		if(num[x][x])return ;
		if(!check())return ;
		for(int i=1;i<=Mx;++i)
			for(int j=1;j<=Mx;++j)
				if(num[i][j])
					ans[++ans_t]=(aaa){pw[i-1],pw[j-1]};
		return (void)(ok=1);
	}
	int t,t1;
	if(num[x][y]>=num[x][x])//1.buliu - quan >= num[x][x] - quan -> num[x][x] sheng -> num[y][y]
	{
		t=num[x][x],t1=num[x][y]-t;
		if(num[y][y]>=t1)
		{
			num[x][x]-=t,num[y][y]-=t1,num[x][y]-=t+t1;
			if(y==x+1)dfs2(x+1,Mx);else dfs2(x,y-1);
			if(ok)
			{
				for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
				for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
				return ;
			}
			num[x][x]+=t,num[y][y]+=t1,num[x][y]+=t+t1;
		}
	}
	else//2.buliu - quan < num[x][x] - quan -> num[x][x]
	{
		t=num[x][y],t1=num[x][y]-t;
		if(num[y][y]>=t1)
		{
			num[x][x]-=t,num[y][y]-=t1,num[x][y]-=t+t1;
			if(y==x+1)dfs2(x+1,Mx);else dfs2(x,y-1);
			if(ok)
			{
				for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
				for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
				return ;
			}
			num[x][x]+=t,num[y][y]+=t1,num[x][y]+=t+t1;
		}
	}
	if(num[x][y]>=num[y][y])//3.buliu - quan >= num[y][y] - quan -> num[y][y] sheng -> num[x][x]
	{
		t=num[y][y],t1=num[x][y]-t;
		if(num[x][x]>=t1)
		{
			num[y][y]-=t,num[x][x]-=t1,num[x][y]-=t+t1;
			if(y==x+1)dfs2(x+1,Mx);else dfs2(x,y-1);
			if(ok)
			{
				for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
				for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
				return ;
			}
			num[y][y]+=t,num[x][x]+=t1,num[x][y]+=t+t1;
		}
	}
	else//4.buliu - quan < num[y][y] - quan -> num[y][y]
	{
		t=num[x][y],t1=num[x][y]-t;
		if(num[x][x]>=t1)
		{
			num[y][y]-=t,num[x][x]-=t1,num[x][y]-=t+t1;
			if(y==x+1)dfs2(x+1,Mx);else dfs2(x,y-1);
			if(ok)
			{
				for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
				for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
				return ;
			}
			num[y][y]+=t,num[x][x]+=t1,num[x][y]+=t+t1;
		}
	}
	if(num[x][y])
	{
		if(num[x][y]-1>=num[x][x])//5.liu - quan >= num[x][x] - quan -> num[x][x] sheng -> num[y][y]
		{
			t=num[x][x],t1=num[x][y]-1-t;
			if(num[y][y]>=t1)
			{
				num[x][x]-=t,num[y][y]-=t1,num[x][y]-=t+t1;
				if(y==x+1)dfs2(x+1,Mx);else dfs2(x,y-1);
				if(ok)
				{
					for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
					for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
					return ;
				}
				num[x][x]+=t,num[y][y]+=t1,num[x][y]+=t+t1;
			}
		}
		else//6.liu - quan < num[x][x] - quan -> num[x][x]
		{
			t=num[x][y]-1,t1=num[x][y]-1-t;
			if(num[y][y]>=t1)
			{
				num[x][x]-=t,num[y][y]-=t1,num[x][y]-=t+t1;
				if(y==x+1)dfs2(x+1,Mx);else dfs2(x,y-1);
				if(ok)
				{
					for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
					for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
					return ;
				}
				num[x][x]+=t,num[y][y]+=t1,num[x][y]+=t+t1;
			}
		}
		if(num[x][y]-1>=num[y][y])//7.liu - quan >= num[y][y] - quan -> num[y][y] sheng -> num[x][x]
		{
			t=num[y][y],t1=num[x][y]-1-t;
			if(num[x][x]>=t1)
			{
				num[y][y]-=t,num[x][x]-=t1,num[x][y]-=t+t1;
				if(y==x+1)dfs2(x+1,Mx);else dfs2(x,y-1);
				if(ok)
				{
					for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
					for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
					return ;
				}
				num[y][y]+=t,num[x][x]+=t1,num[x][y]+=t+t1;
			}
		}
		else//8.liu - quan < num[y][y] - quan -> num[y][y]
		{
			t=num[x][y]-1,t1=num[x][y]-1-t;
			if(num[x][x]>=t1)
			{
				num[y][y]-=t,num[x][x]-=t1,num[x][y]-=t+t1;
				if(y==x+1)dfs2(x+1,Mx);else dfs2(x,y-1);
				if(ok)
				{
					for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
					for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
					return ;
				}
				num[y][y]+=t,num[x][x]+=t1,num[x][y]+=t+t1;
			}
		}
	}
}
inline void dfs3(int x,int y)
{
	
	if(x==1)if(num[y+1][y+1])return ;
	if(y==1)
	{
		if(num[y][y])return ;
		if(!check())return ;
		for(int i=1;i<=Mx;++i)
			for(int j=1;j<=Mx;++j)
				if(num[i][j])
					ans[++ans_t]=(aaa){pw[i-1],pw[j-1]};
		return (void)(ok=1);
	}
	int t,t1;
	if(num[x][y]>=num[x][x])//1.buliu - quan >= num[x][x] - quan -> num[x][x] sheng -> num[y][y]
	{
		t=num[x][x],t1=num[x][y]-t;
		if(num[y][y]>=t1)
		{
			num[x][x]-=t,num[y][y]-=t1,num[x][y]-=t+t1;
			if(x==y-1)dfs3(1,y-1);else dfs3(x+1,y);
			if(ok)
			{
				for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
				for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
				return ;
			}
			num[x][x]+=t,num[y][y]+=t1,num[x][y]+=t+t1;
		}
	}
	else//2.buliu - quan < num[x][x] - quan -> num[x][x]
	{
		t=num[x][y],t1=num[x][y]-t;
		if(num[y][y]>=t1)
		{
			num[x][x]-=t,num[y][y]-=t1,num[x][y]-=t+t1;
			if(x==y-1)dfs3(1,y-1);else dfs3(x+1,y);
			if(ok)
			{
				for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
				for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
				return ;
			}
			num[x][x]+=t,num[y][y]+=t1,num[x][y]+=t+t1;
		}
	}
	if(num[x][y]>=num[y][y])//3.buliu - quan >= num[y][y] - quan -> num[y][y] sheng -> num[x][x]
	{
		t=num[y][y],t1=num[x][y]-t;
		if(num[x][x]>=t1)
		{
			num[y][y]-=t,num[x][x]-=t1,num[x][y]-=t+t1;
			if(x==y-1)dfs3(1,y-1);else dfs3(x+1,y);
			if(ok)
			{
				for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
				for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
				return ;
			}
			num[y][y]+=t,num[x][x]+=t1,num[x][y]+=t+t1;
		}
	}
	else//4.buliu - quan < num[y][y] - quan -> num[y][y]
	{
		t=num[x][y],t1=num[x][y]-t;
		if(num[x][x]>=t1)
		{
			num[y][y]-=t,num[x][x]-=t1,num[x][y]-=t+t1;
			if(x==y-1)dfs3(1,y-1);else dfs3(x+1,y);
			if(ok)
			{
				for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
				for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
				return ;
			}
			num[y][y]+=t,num[x][x]+=t1,num[x][y]+=t+t1;
		}
	}
	if(num[x][y])
	{
		if(num[x][y]-1>=num[x][x])//5.liu - quan >= num[x][x] - quan -> num[x][x] sheng -> num[y][y]
		{
			t=num[x][x],t1=num[x][y]-1-t;
			if(num[y][y]>=t1)
			{
				num[x][x]-=t,num[y][y]-=t1,num[x][y]-=t+t1;
				if(x==y-1)dfs3(1,y-1);else dfs3(x+1,y);
				if(ok)
				{
					for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
					for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
					return ;
				}
				num[x][x]+=t,num[y][y]+=t1,num[x][y]+=t+t1;
			}
		}
		else//6.liu - quan < num[x][x] - quan -> num[x][x]
		{
			t=num[x][y]-1,t1=num[x][y]-1-t;
			if(num[y][y]>=t1)
			{
				num[x][x]-=t,num[y][y]-=t1,num[x][y]-=t+t1;
				if(x==y-1)dfs3(1,y-1);else dfs3(x+1,y);
				if(ok)
				{
					for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
					for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
					return ;
				}
				num[x][x]+=t,num[y][y]+=t1,num[x][y]+=t+t1;
			}
		}
		if(num[x][y]-1>=num[y][y])//7.liu - quan >= num[y][y] - quan -> num[y][y] sheng -> num[x][x]
		{
			t=num[y][y],t1=num[x][y]-1-t;
			if(num[x][x]>=t1)
			{
				num[y][y]-=t,num[x][x]-=t1,num[x][y]-=t+t1;
				if(x==y-1)dfs3(1,y-1);else dfs3(x+1,y);
				if(ok)
				{
					for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
					for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
					return ;
				}
				num[y][y]+=t,num[x][x]+=t1,num[x][y]+=t+t1;
			}
		}
		else//8.liu - quan < num[y][y] - quan -> num[y][y]
		{
			t=num[x][y]-1,t1=num[x][y]-1-t;
			if(num[x][x]>=t1)
			{
				num[y][y]-=t,num[x][x]-=t1,num[x][y]-=t+t1;
				if(x==y-1)dfs3(1,y-1);else dfs3(x+1,y);
				if(ok)
				{
					for(int i=1;i<=t;++i)ans[++ans_t]=(aaa){(++idx[y]),pw[x-1]};
					for(int i=1;i<=t1;++i)ans[++ans_t]=(aaa){(++idx[x]),pw[y-1]};
					return ;
				}
				num[y][y]+=t,num[x][x]+=t1,num[x][y]+=t+t1;
			}
		}
	}
}
int main()
{
	scanf("%d",&n),pw[0]=1;
	for(int i=1;i<=n;i*=10)++Mx,pw[Mx]=pw[Mx-1]*10;
	for(int i=1;i<Mx;++i)
		for(int j=pw[i-1];j<pw[i];++j)
			w[j]=i;
	for(int i=pw[Mx-1];i<=n;++i)w[i]=Mx;
	for(int i=1;i<n;++i)
	{
		scanf("%s",s),l1=strlen(s),scanf("%s",s),l2=strlen(s);
		++cnt[l1][l2];if(l1>l2)swap(l1,l2);++num[l1][l2];
	}
	for(int i=1;i<Mx;++i)
	{
		idx[i]=pw[i-1];
		for(int j=1;j<=num[i][i];++j)
			ans[++ans_t]=(aaa){pw[i-1],(++idx[i])};
		num[i][i]-=9*pw[i-1]-1;
	}
	idx[Mx]=pw[Mx-1];
	for(int j=1;j<=num[Mx][Mx];++j)
		ans[++ans_t]=(aaa){pw[Mx-1],(++idx[Mx])};
	num[Mx][Mx]-=n-pw[Mx-1];
	for(int i=1;i<=Mx;++i)
		if((num[i][i]*=-1)<0)
			return 0&puts("-1");
	ok=(ans_t==n-1);
	if(!ok)dfs(1,2);
	if(!ok)dfs1(Mx-1,Mx);
	if(!ok)dfs2(1,Mx);
	if(!ok)dfs3(1,Mx);
	if(ans_t!=n-1)return 0&puts("-1");
	for(int i=1,x,y;i<=ans_t;++i)
	{
		x=ans[i].x,y=ans[i].y;
		if(cnt[w[x]][w[y]])printf("%d %d\n",x,y),--cnt[w[x]][w[y]];
		else printf("%d %d\n",y,x),--cnt[w[y]][w[x]];
	}
	return 0;
}
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int t,h,i,j,K[1000],p[1000][5],ans,q[2][1000],l[2],g,dep;
bool v[1000];
void Ask(int x)
{
	if(K[x])
		return;
	cout<<'?'<<' '<<x<<endl;
	cout.flush();
	cin>>K[x];
	for(int j=1;j<=K[x];++j)
		cin>>p[x][j];
}
void work(int x,int lst,int id)
{
	v[x]=true;
	Ask(x);
	q[id][++l[id]]=x;
	if(K[x]==2)
	{
		ans=x;
		return;
	}
	if(K[x]==1)
		return;
	int a=p[x][1],b=p[x][2],c=p[x][3];
	if(a!=lst)
		work(a,x,id);
	else if(b!=lst)
		work(b,x,id);
	else
		work(c,x,id);
}
int dzx(int x,int lst,int dep)
{
	Ask(x);
	if(K[x]==1)
		return dep==h?1:0;
	if(K[x]==2)
		return -x;
	if(dep==h)
		return 0;
	if(!v[p[x][1]]&&p[x][1]!=lst)
		return dzx(p[x][1],x,dep+1);
	else if(!v[p[x][2]]&&p[x][2]!=lst)
		return dzx(p[x][2],x,dep+1);
	else
		return dzx(p[x][3],x,dep+1);
}
void tk(int x,int d)
{
	if(ans!=-1)
		return;
	if(j==6)
	{
		ans=x;
		return;
	}
	v[x]=true;
	Ask(x);
	++j;
	if(K[x]==2)
	{
		ans=x;
		return;
	}
	if(K[x]==1||d==0)
		return;
	if(!v[p[x][1]])
		tk(p[x][1],d-1);
	if(!v[p[x][2]])
		tk(p[x][2],d-1);
	if(!v[p[x][3]])
		tk(p[x][3],d-1);
}
int dfs(int x,int dep)
{
	v[x]=true;
	Ask(x);
	if(K[x]==2)
		return x;
	if(dep==2)
	{
		for(int y=1;y<=K[x];++y)
			if(!v[p[x][y]])
			{
				Ask(p[x][y]);
				if(K[p[x][y]]==2)
					return p[x][y];
				else
					return !v[p[x][y+1]]?p[x][y+1]:p[x][y+2];
			}
	}
	if(dep==3)
	{
		ans=-1;
		j=0;
		tk(x,2);
		return ans;
	}
	for(int y=1;y<=K[x];++y)
		if(!v[p[x][y]])
		{
			int z=dzx(p[x][y],x,dep+1);
			if(z<0)
				return -z;
			if(!z)
				return dfs(p[x][y],dep-1);
			else
				return dfs(!v[p[x][y+1]]?p[x][y+1]:p[x][y+2],dep-1);
		}
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>h;
		for(i=1;i<(1<<h);++i)
			v[i]=false,K[i]=0;
		v[1]=true;
		Ask(1);
		if(K[1]==2)
		{
			cout<<'!'<<' '<<1<<endl;
			cout.flush();
			continue;
		}
		ans=-1;
		if(K[1]==1)
			g=1,dep=h;
		else
		{
			i=p[1][1],j=p[1][2];
			l[0]=l[1]=0;
			work(i,1,0);
			work(j,1,1);
			if(ans!=-1)
			{
				cout<<'!'<<' '<<ans<<endl;
				cout.flush();
				continue;
			}
			if(l[0]==l[1])
				g=1,dep=h-l[0];
			else if(l[0]>l[1])
				g=q[0][(l[0]-l[1])/2],dep=h-l[1]-(l[0]-l[1])/2;
			else
				g=q[1][(l[1]-l[0])/2],dep=h-l[0]-(l[1]-l[0])/2;
		}
		Ask(g);
		for(i=1;i<=K[g];++i)
			if(!v[p[g][i]])
				break;
		g=p[g][i],dep--;
		cout<<'!'<<' '<<dfs(g,dep)<<endl;
		cout.flush();
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int N,n,m,dif,ans_t=0,la2=-1,la3=-1,vec_t=0;
int a[200002],rt[200002],siz[200002];
bool y[200002]={},u[200002]={};
vector<int> vec[200002];
struct aaa
{
	int x,y;
}ans[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void SW(int kx,int x,int ky,int y)
{
	ans[++ans_t]=(aaa){vec[kx][x],vec[ky][y]};
}
int main()
{
	read(N);
	for(int i=1;i<=N;++i)read(a[i]),rt[i]=i,siz[i]=1;
	for(int i=1;i<=N;++i)
	{
		getroot(a[i]),getroot(i);
		if(rt[i]!=rt[a[i]])siz[rt[a[i]]]+=siz[rt[i]],rt[rt[i]]=rt[a[i]];
	}
	for(int i=1,j;i<=N;++i)
	{
		getroot(i);if(y[rt[i]])continue;
		y[rt[i]]=1;if(siz[rt[i]]==1)continue;
		for(j=i;!u[j];)vec[vec_t].push_back(j),u[j]=1,j=a[j];
		++vec_t;
	}
	for(int i=0;i<vec_t;++i)
	{
		if(vec[i].size()==2)
		{
			if(!(~la2)){la2=i;continue;}
			SW(la2,1,i,0),SW(la2,1,i,1),SW(la2,0,i,0),SW(la2,1,i,0),la2=-1;
		}
		else
		{
			if(!(~la3)){la3=i;continue;}
			n=vec[la3].size(),m=vec[i].size(),SW(la3,n-1,i,0);
			for(int j=0;j<n-1;++j)SW(la3,j,i,0);
			for(int j=1;j<m;++j)SW(i,j,la3,n-1);
			SW(la3,n-1,i,0),la3=-1;
		}
	}
	if(~la2)
	{
		if(~la3)
		{
			n=vec[la3].size();
			for(int i=0;i<n;++i)SW(la3,i,la2,0);
			SW(la3,0,la2,1),SW(la3,0,la2,0);
		}
		else
		{
			for(int i=1;i<=N;++i)if(i!=vec[la2][0] && i!=vec[la2][1]){dif=i;break;}
			ans[++ans_t]=(aaa){vec[la2][0],dif},ans[++ans_t]=(aaa){vec[la2][1],dif},ans[++ans_t]=(aaa){vec[la2][0],dif};
		}
	}
	else
	{
		if(~la3)
		{
			n=vec[la3].size();
			SW(la3,n-1,la3,n-2),SW(la3,n-1,la3,0),SW(la3,n-2,la3,0);
			for(int j=1;j<=n-2;++j)SW(la3,j,la3,n-1);
		}
	}
	printf("%d\n",ans_t);
	for(int i=1;i<=ans_t;++i)printf("%d %d\n",ans[i].x,ans[i].y);
	return 0;
}
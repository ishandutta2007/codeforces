#include<bits/stdc++.h>
#define LL long long
#define Mx 1000000000000LL
#define Mx1 2000000000000LL
using namespace std;
int n,a=1,b=2,son_t;
int X[200002],Y[200002],val[200002],ans[200002];
vector<int> son[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL pw(LL x)
{
	return x*x;
}
inline void dfs(int x,int y)
{
	if(x<=n)ans[x]=y;
	for(int i=0;i<son[x].size();++i)dfs(son[x][i],y*val[son[x][i]]);
}
int main()
{
	read(n),son_t=n;
	for(int i=1;i<=n;++i)read(X[i]),read(Y[i]);
	if(n<=2)
	{
		for(int i=1,x=0,y=0;i<=n;++i)
		{
			if(pw(x+X[i])+pw(y+Y[i])<=Mx1)x+=X[i],y+=Y[i],printf("1 ");
			else x-=X[i],y-=Y[i],printf("-1 ");
		}
		return 0;
	}
	for(int i=3;i<=n;++i)
	{
		if(pw(X[a]+X[b])+pw(Y[a]+Y[b])<=Mx)val[a]=val[b]=1,X[++son_t]=X[a]+X[b],Y[son_t]=Y[a]+Y[b],son[son_t].push_back(a),son[son_t].push_back(b),a=son_t,b=i;
		else if(pw(X[a]-X[b])+pw(Y[a]-Y[b])<=Mx)val[a]=1,val[b]=-1,X[++son_t]=X[a]-X[b],Y[son_t]=Y[a]-Y[b],son[son_t].push_back(a),son[son_t].push_back(b),a=son_t,b=i;
		else if(pw(X[a]+X[i])+pw(Y[a]+Y[i])<=Mx)val[a]=val[i]=1,X[++son_t]=X[a]+X[i],Y[son_t]=Y[a]+Y[i],son[son_t].push_back(a),son[son_t].push_back(i),a=son_t;
		else if(pw(X[a]-X[i])+pw(Y[a]-Y[i])<=Mx)val[a]=1,val[i]=-1,X[++son_t]=X[a]-X[i],Y[son_t]=Y[a]-Y[i],son[son_t].push_back(a),son[son_t].push_back(i),a=son_t;
		else if(pw(X[b]+X[i])+pw(Y[b]+Y[i])<=Mx)val[b]=val[i]=1,X[++son_t]=X[b]+X[i],Y[son_t]=Y[b]+Y[i],son[son_t].push_back(b),son[son_t].push_back(i),b=son_t;
		else if(pw(X[b]-X[i])+pw(Y[b]-Y[i])<=Mx)val[b]=1,val[i]=-1,X[++son_t]=X[b]-X[i],Y[son_t]=Y[b]-Y[i],son[son_t].push_back(b),son[son_t].push_back(i),b=son_t;
	}
	if(pw(X[a]+X[b])+pw(Y[a]+Y[b])<=Mx1)val[a]=val[b]=1;else val[a]=1,val[b]=-1;
	dfs(a,val[a]),dfs(b,val[b]);
	for(int i=1;i<=n;++i)printf("%d%c",ans[i],i==n? '\n':' ');
	return 0;
}
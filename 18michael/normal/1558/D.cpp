#include<bits/stdc++.h>
#define Mx 400000
#define Mx2 200001
#define LL long long
#define mod 998244353
using namespace std;
int n,m,t,Test_num;
LL ans;
int fa[200002],siz[200002],X[200002],Y[200002];
int son[200002][2];
LL fac[400002],inv[400002];
inline LL Pow(int a,int b)
{
	if(!b)return 1;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void init()
{
	fac[0]=1;for(int i=1;i<=Mx;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[Mx]=Pow(fac[Mx],mod-2);for(int i=Mx;i;--i)inv[i-1]=(inv[i]*i)%mod;
	siz[Mx2]=Mx2;for(int i=1;i<Mx2;++i)siz[i]=i,fa[i]=i+1,son[i+1][0]=i;
}
inline LL C(int a,int b)
{
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
inline bool Get(int x)
{
	return x==son[fa[x]][1];
}
inline void PushUp(int x)
{
	if(x)siz[x]=siz[son[x][0]]+siz[son[x][1]]+1;
}
inline void Rotate(int x)
{
	int y=fa[x],gx=Get(x),gy=Get(y),z=son[x][gx^1],w=fa[y];
	son[w][gy]=x,fa[x]=w,son[x][gx^1]=y,fa[y]=x,son[y][gx]=z,fa[z]=y,PushUp(y),PushUp(x);
}
inline void Splay(int x)
{
	for(;fa[x];Rotate(x))if(fa[fa[x]])Rotate(Get(x)==Get(fa[x])? fa[x]:x);
}
inline int Find(int now,int x)
{
	for(;;)
	{
		if(siz[son[now][0]]>=x)now=son[now][0];
		else
		{
			if(!(x-=siz[son[now][0]]+1))return now;
			now=son[now][1];
		}
	}
}
inline void solve()
{
	scanf("%d%d",&n,&m),t=ans=0;
	for(int i=1,x,y,z;i<=m;++i)
	{
		scanf("%d%d",&X[i],&Y[i]),Splay(X[i]),x=Find(X[i],X[i]-1),y=Find(X[i],X[i]+1),son[X[i]][0]=son[X[i]][1]=fa[son[X[i]][0]]=fa[son[X[i]][1]]=0,siz[X[i]]=1,Splay(x),Splay(y),son[x][1]=y,fa[y]=x,PushUp(x);
		if(Y[i]>1)Splay(z=Find(x,Y[i]-1)),Splay(Y[i]=Find(z,Y[i])),son[son[Y[i]][0]][1]=X[i],fa[X[i]]=son[Y[i]][0],PushUp(son[Y[i]][0]),PushUp(Y[i]);
		else Splay(Y[i]=Find(x,Y[i])),son[Y[i]][0]=X[i],fa[X[i]]=Y[i],PushUp(Y[i]);
	}
	for(int i=1,x;i<=m;++i)Splay(Y[i]),x=siz[son[Y[i]][0]],Splay(X[i]),t+=(x==siz[son[X[i]][0]]+1);
	printf("%lld\n",C(2*n-1-t,n));
	for(int i=m,x,y;i;--i)
	{
		Splay(X[i]);
		if(siz[son[X[i]][0]])x=Find(X[i],siz[son[X[i]][0]]),y=Find(X[i],siz[son[X[i]][0]]+2),son[X[i]][0]=son[X[i]][1]=fa[son[X[i]][0]]=fa[son[X[i]][1]]=0,siz[X[i]]=1,Splay(x),Splay(y),son[x][1]=y,fa[y]=x,PushUp(x);
		else x=Find(X[i],siz[son[X[i]][0]]+2),son[X[i]][0]=son[X[i]][1]=fa[son[X[i]][0]]=fa[son[X[i]][1]]=0,siz[X[i]]=1,Splay(x);
		y=Find(x,X[i]-1),x=Find(x,X[i]),Splay(y),Splay(x),fa[y]=X[i],son[X[i]][0]=y,fa[X[i]]=x,son[x][0]=X[i],PushUp(X[i]),PushUp(x);
	}
}
int main()
{
	for(init(),scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}
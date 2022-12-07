#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=200005;
LL n,m;
struct qq
{
	LL x,y,last;
}e[N*2];LL num,last[N];
struct path
{
	LL x,y,c;
	path() {}
	path(LL _x,LL _y,LL _c)	{x=_x;y=_y;c=_c;}
};
void init (LL x,LL y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
LL fa[N][21];
LL dep[N];
void dfs (LL x)
{
	for (LL u=1;u<=20;u++)	fa[x][u]=fa[fa[x][u-1]][u-1];
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (y==fa[x][0]) continue;
		fa[y][0]=x;dep[y]=dep[x]+1;
		dfs(y);
	}
}
LL lca (LL x,LL y)
{
	if (dep[y]>dep[x]) swap(x,y);
	for (LL u=20;u>=0;u--)
		if (dep[fa[x][u]]>=dep[y])
			x=fa[x][u];
	if (x==y) return x;
	for (LL u=20;u>=0;u--)
		if (fa[x][u]!=fa[y][u])
			x=fa[x][u],y=fa[y][u];
	return fa[x][0];
}
LL s[5];
bool cmp (LL a,LL b)	{return dep[a]<dep[b];}
path mix (path x,path y)
{
	if (x.c==0||y.c==0) return path(0,0,0);
	s[1]=lca(x.x,y.x);s[2]=lca(x.x,y.y);
	s[3]=lca(x.y,y.x);s[4]=lca(x.y,y.y);
	sort(s+1,s+1+4,cmp);
	LL mx=max(dep[x.c],dep[y.c]),mn=min(dep[x.c],dep[y.c]);
	if (dep[s[1]]<mn||dep[s[3]]<mx) return path(0,0,0);
	return path(s[3],s[4],lca(s[3],s[4]));
}
LL dis (LL x,LL y)// 
{
	LL z=lca(x,y);
	return dep[x]+dep[y]-2*dep[z];
}
LL mymin (LL x,LL y)
{
	if (x==-1) return y;
	if (y==-1) return x;
	return x<y?x:y;
}
LL exgcd (LL a,LL b,LL &x,LL &y)
{
	if (a==0)	{x=0;y=1;return b;}
	LL tx,ty;
	LL d=exgcd(b%a,a,tx,ty);
	y=tx;x=ty-(b/a)*tx;
	return d;
}
LL same (LL t1,LL t2,LL f1,LL f2)//   
{
//	printf("YES:%lld %lld %lld %lld\n",t1,t2,f1,t2);
	LL tx,ty;
	LL d=exgcd(f1,f2,tx,ty);
	LL t=((t2-t1)%f2+f2)%f2;
	if (t%d!=0) return -1;
	tx=(tx*(t/d)%(f2/d)+(f2/d))%(f2/d);
	return tx*f1+t1;
}
LL G (LL M,LL D,LL L,LL R)
{
	LL t=L/D;
	if (t*D<L) t++;
	if (t*D<=R) return t;
	if (2*D>M) return G(M,M-D,M-R,M-L);
	LL k=G(D,(-M%D+D)%D,L%D,R%D);
	L=L+M*k;R=R+M*k;
	t=L/D;
	if (t*D<L) t++;
	return t; 
}
LL make (LL M,LL D,LL L,LL R)
{
	LL tx,ty;
	LL g=exgcd(M,D,tx,ty);
	if ((L-1)/g>=R/g) return -1;
	return G(M,D,L,R);
}
LL diff (LL t1,LL t2,LL f1,LL f2,LL d)//t1t2   f1f2   d 
{
	LL l=t2-t1-d,r=t2-t1+d;
	l=(l%f2+f2)%f2;
	r=(r%f2+f2)%f2;
	if (l%2!=0) return -1;
	//p0
if(l>r || l==0) return t1+r/2;
    if(f2==d*2) return t1+r/2;
	LL p=make(f2,f1%f2,l,r);
	if (p==-1) return p;
	//printf("%lld %lld %lld %lld %lld\n",t1,t2,f1,f2,p);
	 
	return p*f1+t1+d-p*f1%f2/2+l/2;
}
LL solve (path x,path y)
{
	path z=mix(x,y);	
	//printf("YES:%lld %lld\n",z.x,z.y);
	if (z.c==0) return -1;
	LL d=dis(z.x,z.y),f1=2*dis(x.x,x.y),f2=2*dis(y.x,y.y);
	LL d1,d2;
	LL t1,t2,t3,t4;

	d1=dis(x.x,z.x);d2=dis(x.x,z.y);
	if (d1<d2) t1=d1,t2=f1-d2;
	else t1=f1-d1,t2=d2;
	d1=dis(y.x,z.x);d2=dis(y.x,z.y);
	if (d1<d2) t3=d1,t4=f2-d2;
	else t3=f2-d1,t4=d2;
	LL ans=-1;
	ans=mymin(ans,same(t1,t3,f1,f2));
	ans=mymin(ans,same(t2,t4,f1,f2));
	//printf("%lld\n",ans);
	ans=mymin(ans,diff(t1,t4,f1,f2,d));
	ans=mymin(ans,diff(t2,t3,f1,f2,d));
	return ans;
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%lld",&n);
	for (LL u=1;u<n;u++)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		init(x,y);init(y,x);
	}
	dep[1]=1;dfs(1);
	scanf("%lld",&m);
	for (LL u=1;u<=m;u++)
	{
		LL a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		printf("%lld\n",solve(path(a,b,lca(a,b)),path(c,d,lca(c,d))));
	}
	return 0;
}
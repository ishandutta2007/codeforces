#include<bits/stdc++.h>
#define ldb long double
using namespace std;
const ldb pai=acos(-1)*3/2;
int n,q,p1=1,p2=2;
ldb sum,res,Theta=0;
struct Vec
{
	ldb x,y;
}v[10002],V,G;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline ldb cross(Vec a,Vec b)
{
	return a.x*b.y-a.y*b.x;
}
inline Vec add(Vec a,Vec b)
{
	return (Vec){a.x+b.x,a.y+b.y};
}
inline Vec mns(Vec a,Vec b)
{
	return (Vec){a.x-b.x,a.y-b.y};
}
inline Vec mul(Vec a,ldb b)
{
	return (Vec){a.x*b,a.y*b};
}
inline Vec div(Vec a,ldb b)
{
	return (Vec){a.x/b,a.y/b};
}
inline Vec rotate(Vec a,ldb b)
{
	return (Vec){a.x*cos(b)-a.y*sin(b),a.x*sin(b)+a.y*cos(b)};
}
inline void print(Vec a)
{
	printf("%.10Lf %.10Lf\n",a.x,a.y);
}
int main()
{
	read(n),read(q),G=(Vec){0,0};
	for(int i=1;i<=n;++i)scanf("%Lf%Lf",&v[i].x,&v[i].y);
	for(int i=2;i<n;++i)G=add(G,mul(add(v[1],add(v[i],v[i+1])),(res=cross(mns(v[i],v[1]),mns(v[i+1],v[1])))/3)),sum+=res;
	G=div(G,sum);for(int i=1;i<=n;++i)v[i]=mns(v[i],G);
	for(int opt,x,y;q--;)
	{
		read(opt),read(x);
		if(opt==1)
		{
			read(y);if(x!=p2)swap(p1,p2);
			V=add(G,rotate(v[p1],Theta)),G=mns(G,V),Theta+=(res=pai-atan2(G.y,G.x)),G=add(rotate(G,res),V),p2=y;
		}
		else print(add(G,rotate(v[x],Theta)));
	}
	return 0;
}
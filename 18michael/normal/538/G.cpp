#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,l;
LL t,x,y,mnx=0,mxx,mny=0,mxy;
int id[200002];
LL a[200002],b[200002],X[200002],Y[200002];
inline bool cmp(int x,int y)
{
	return b[x]<b[y]? 1:0;
}
inline bool calc(LL &mnx,LL &mxx,LL a,LL b)
{
	return a? ((a>0? mnx=max(mnx,(LL)ceil(1.0l*b/a)):mxx=min(mxx,(LL)floor(1.0l*b/a))),0):(b>0);
}
int main()
{
	scanf("%d%d",&n,&l),mxx=mxy=l;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld%lld",&t,&x,&y),id[i]=i;
		if((t+x+y)&1)return 0&puts("NO");
		a[i]=t/l,b[i]=t%l,X[i]=(x+y+t)/2,Y[i]=(x-y+t)/2;
	}
	++n,a[n]=-1,b[n]=l,id[n]=n,X[n]=Y[n]=a[0]=b[0]=X[0]=Y[0]=id[0]=0,sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;++i)if(calc(mnx,mxx,a[id[i]]-a[id[i-1]],X[id[i]]-X[id[i-1]]-b[id[i]]+b[id[i-1]]) || calc(mnx,mxx,a[id[i-1]]-a[id[i]],X[id[i-1]]-X[id[i]]) || calc(mny,mxy,a[id[i]]-a[id[i-1]],Y[id[i]]-Y[id[i-1]]-b[id[i]]+b[id[i-1]]) || calc(mny,mxy,a[id[i-1]]-a[id[i]],Y[id[i-1]]-Y[id[i]]))return 0&puts("NO");
	if(mnx>mxx || mny>mxy)return 0&puts("NO");
	for(int i=0;i<=n;++i)X[id[i]]-=a[id[i]]*mnx,Y[id[i]]-=a[id[i]]*mny;
	for(int i=1;i<=n;++i)
		for(int j=b[id[i-1]]+1;j<=b[id[i]];++j)
		{
			if(X[id[i-1]]<X[id[i]] && Y[id[i-1]]<Y[id[i]])putchar('R'),++X[id[i-1]],++Y[id[i-1]];
			else if(X[id[i-1]]<X[id[i]])putchar('U'),++X[id[i-1]];
			else if(Y[id[i-1]]<Y[id[i]])putchar('D'),++Y[id[i-1]];
			else putchar('L');
		}
	return 0;
}
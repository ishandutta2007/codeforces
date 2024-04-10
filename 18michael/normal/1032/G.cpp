#include<bits/stdc++.h>
#define Mx 18
#define eps 1e-8
using namespace std;
int n,ans;
int a[300002];
int l[300002][22],r[300002][22],L[300002][22],R[300002][22];
inline int mergel(int x,int y)
{
	return x-a[x]<y-a[y]? x:y;
}
inline int merger(int x,int y)
{
	return x+a[x]>y+a[y]? x:y;
}
inline int getl(int x,int y)
{
	int len=log2(y-x+1)+eps;
	return mergel(l[x][len],l[y-(1<<len)+1][len]);
}
inline int getr(int x,int y)
{
	int len=log2(y-x+1)+eps;
	return merger(r[x][len],r[y-(1<<len)+1][len]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[n+i]=a[2*n+i]=a[i];
	n*=3;
	for(int i=1;i<=n;++i)l[i][0]=r[i][0]=i,L[i][0]=max(1,i-a[i]),R[i][0]=min(n,i+a[i]);
	for(int i=1;i<=Mx;++i)
		for(int j=1;j+(1<<i)-1<=n;++j)
			l[j][i]=mergel(l[j][i-1],l[j+(1<<(i-1))][i-1]),r[j][i]=merger(r[j][i-1],r[j+(1<<(i-1))][i-1]);
	for(int i=1,x,y;i<=Mx;++i)
		for(int j=1;j<=n;++j)
			x=getl(L[j][i-1],R[j][i-1]),y=getr(L[j][i-1],R[j][i-1]),L[j][i]=min(L[x][i-1],L[y][i-1]),R[j][i]=max(R[x][i-1],R[y][i-1]);
	n/=3;
	for(int i=n+1;i<=2*n;++i)
	{
		ans=0;
		for(int j=Mx,x=i,y=i,X,Y;~j;--j)
			if((Y=max(R[x][j],R[y][j]))-(X=min(L[x][j],L[y][j]))+1<n)
				x=getl(X,Y),y=getr(X,Y),ans+=(1<<j);
		printf("%d ",ans+(n>1));
	}
	return 0;
}
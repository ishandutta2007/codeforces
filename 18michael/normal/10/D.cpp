#include<bits/stdc++.h>
using namespace std;
int n,m,B,nowa=0,nowb=0,nowc=0,na,nb,nc;
int a[502],b[502];
int f[25][502][502],g[25][502][502],from[25][502][502];
vector<int> vec;
inline void upd(int &x,int y)
{
	if(y>x)x=y;
}
inline int num(int x,int y,int z)
{
	return ((((x<<9)|y)<<9)|z);
}
inline void upd1(int a,int b,int c,int x,int y,int z,int w)
{
	if(f[x][y][z]+w>f[a][b][c])f[a][b][c]=f[x][y][z]+w,from[a][b][c]=num(x,y,z);
}
int main()
{
	scanf("%d",&n),a[0]=-1,B=sqrt(n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)scanf("%d",&b[i]);
	for(int o=1,ed;o<=n;o+=B)
	{
		ed=min(n,o+B-1);
		for(int j=1;j<=m+1;++j)
			for(int k=0;k<=n;++k)
				f[0][j][k]=g[o/B][j][k];
		for(int i=o;i<=ed;++i)
		{
			for(int j=1;j<=m+1;++j)
				for(int k=0;k<=n;++k)
					f[i-o+1][j][k]=0;
			for(int j=1;j<=m+1;++j)
				for(int k=0;k<=n;++k)
					upd(f[i-o+1][j][k],f[i-o][j][k]);
			for(int j=1;j<=m;++j)
				for(int k=0;k<=n;++k)
					if(a[i]==b[j] && a[i]>a[k])
						upd(f[i-o+1][j+1][i],f[i-o][j][k]+1);
			for(int j=1;j<=m;++j)
				for(int k=0;k<=n;++k)
					upd(f[i-o+1][j+1][k],f[i-o+1][j][k]);
		}
		for(int j=1;j<=m+1;++j)
			for(int k=0;k<=n;++k)
				g[o/B+1][j][k]=f[ed-o+1][j][k];
		if(ed==n)
		{
			nowa=n-o+1,nowb=m+1;
			for(int i=1;i<=n;++i)
				if(f[nowa][nowb][i]>f[nowa][nowb][nowc])
					nowc=i;
		}
	}
	for(int o=(n-1)/B*B+1,ed;o>0;o-=B)
	{
		nowa=(ed=min(n,o+B-1))-o+1;
		for(int j=1;j<=m+1;++j)
			for(int k=0;k<=n;++k)
				f[0][j][k]=g[o/B][j][k];
		for(int i=o;i<=ed;++i)
		{
			for(int j=1;j<=m+1;++j)
				for(int k=0;k<=n;++k)
					f[i-o+1][j][k]=from[i-o+1][j][k]=0;
			for(int j=1;j<=m+1;++j)
				for(int k=0;k<=n;++k)
					upd1(i-o+1,j,k,i-o,j,k,0);
			for(int j=1;j<=m;++j)
				for(int k=0;k<=n;++k)
					if(a[i]==b[j] && a[i]>a[k])
						upd1(i-o+1,j+1,i,i-o,j,k,1);
			for(int j=1;j<=m;++j)
				for(int k=0;k<=n;++k)
					upd1(i-o+1,j+1,k,i-o+1,j,k,0);
		}
		while(nowa && nowc)
		{
			na=(from[nowa][nowb][nowc]>>18),nb=((from[nowa][nowb][nowc]>>9)&511),nc=(from[nowa][nowb][nowc]&511);
			if(nowa-na==1 && nowb-nb==1)vec.push_back(nowc);
			nowa=na,nowb=nb,nowc=nc;
		}
	}
	printf("%d\n",vec.size());
	for(int i=vec.size()-1;~i;--i)printf("%d ",a[vec[i]]);
	return 0;
}
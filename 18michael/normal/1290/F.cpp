#include<bits/stdc++.h>
#define Mx 20
#define mod 998244353
using namespace std;
int n,m,t0=0,t1=1,Mx1;
int Sx[34][2]={},Sy[34][2]={};
int f[2][22][22][22][22][2][2];
inline void upd(int &x,int y)
{
	if((x+=y)>=mod)x-=mod;
}
int main()
{
	scanf("%d%d",&n,&m),Mx1=(1<<n);
	for(int i=0,x,y;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		for(int j=0;j<Mx1;++j)if((j>>i)&1)Sx[j][x>0]+=abs(x),Sy[j][y>0]+=abs(y);
	}
	for(f[0][0][0][0][0][0][0]=1;memset(f[t1],0,sizeof(f[t1])),m;m>>=1,t0^=1,t1^=1)
	for(int i0=0;i0<=Mx;++i0)for(int i1=0;i1<=Mx;++i1)for(int j0=0;j0<=Mx;++j0)for(int j1=0;j1<=Mx;++j1)for(int o0=0;o0<2;++o0)for(int o1=0;o1<2;++o1)
	if(f[t0][i0][i1][j0][j1][o0][o1])for(int S=0;S<Mx1;++S)if(!(((i0+Sx[S][0])^(i1+Sx[S][1]))&1) && !(((j0+Sy[S][0])^(j1+Sy[S][1]))&1))
	upd(f[t1][(i0+Sx[S][0])>>1][(i1+Sx[S][1])>>1][(j0+Sy[S][0])>>1][(j1+Sy[S][1])>>1][(((i0+Sx[S][0])^m)&1)? ((i0+Sx[S][0])&1):o0][(((j0+Sy[S][0])^m)&1)? ((j0+Sy[S][0])&1):o1],f[t0][i0][i1][j0][j1][o0][o1]);
	return 0&printf("%d",(f[t0][0][0][0][0][0][0]+mod-1)%mod);
}
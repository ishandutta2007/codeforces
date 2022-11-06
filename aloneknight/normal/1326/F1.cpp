#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
const int M=200;
int n,a[20][20],b[20],c[20][20],c1[20],c2[20],p[20],f[M][20],f1[M][20],f2[M][20];ll ans[1<<14];char s[20];
inline void sol(int S,int o)
{
	int m=0;rep(i,0,n)if(S>>i&1)b[m++]=i;
	rep(i,0,m)rep(j,0,m)c[i][j]=a[b[i]][b[j]];
	rep(i,0,m)p[i]=i;
	do
	{
		int t=0;
		rep(i,0,m-1)t=t<<1|(c[p[i]][p[i+1]]);
		if(o)f[t][b[p[0]]]++;
		else f[t][b[p[m-1]]]++;
	}
	while(next_permutation(p,p+m));
}
int main()
{
	scanf("%d",&n);
	rep(i,0,n)
	{
		scanf("%s",s);
		rep(j,0,n)a[i][j]=s[j]-'0';
	}
	int nn=1<<n,n1=n/2,n2=n-n1;//0~n1-1,n1~n-1
	int nn1=1<<(n1-1),nn2=1<<(n2-1);
	rep(S1,0,nn)
	{
		int s=0,m1=0,m2=0;
		rep(j,0,n)if(S1>>j&1)s++;
		if(s!=n1)continue;
		int S2=((1<<n)-1)^S1;
		sol(S1,0);rep(i,0,nn1)rep(j,0,n)f1[i][j]=f[i][j],f[i][j]=0;
		sol(S2,1);rep(i,0,nn2)rep(j,0,n)f2[i][j]=f[i][j],f[i][j]=0;
		rep(i,0,n)if(S1>>i&1)c1[m1++]=i;
		rep(i,0,n)if(S2>>i&1)c2[m2++]=i;
		rep(t1,0,m1)rep(t2,0,m2)
		{
			int o1=c1[t1],o2=c2[t2],t=a[o1][o2];
			rep(i,0,nn1)if(f1[i][o1])
			{
				int o=(i<<1|t)<<(n2-1),w=f1[i][o1];
				rep(j,0,nn2)if(f2[j][o2])ans[o|j]+=1ll*w*f2[j][o2];
			}
		}
	} 
	nn=1<<(n-1);
	rep(i,0,nn)printf("%lld ",ans[i]);
	return 0;
}
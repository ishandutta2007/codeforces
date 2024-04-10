#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=125005,MAXM=270003,MOD=998244353;
int n,m,N=1,rev[MAXM];
string a,b;
int x[6][MAXM],y[6][MAXM];
int r[36][MAXM];
int fa[6];
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}
int cnt=0;
void merge(int u,int v)
{
	u=getfa(u);v=getfa(v);
	if(u==v)return;
	fa[u]=v;++cnt;
}
int qmi(int x,int k)
{
	int ans=1;
	for(;k;k>>=1,x=(ll)x*x%MOD)
		if(k&1)ans=(ll)ans*x%MOD;
	return ans;
}
void ntt(int *a,int ty)
{
	for(int i=0;i<N;i++)
		if(rev[i]>i)swap(a[i],a[rev[i]]);
	int wn,w;
	for(int i=1;i<N;i<<=1)
	{
		wn=qmi(ty,(MOD-1)/(i<<1));
		for(int j=0;j<N;j+=(i<<1))
		{
			w=1;
			for(int k=j;k<i+j;++k)
			{
				int t=(ll)a[i+k]*w%MOD;
				a[i+k]=a[k]-t;if(a[i+k]<0)a[i+k]+=MOD;
				a[k]+=t;if(a[k]>=MOD)a[k]-=MOD;
				w=(ll)w*wn%MOD;
			}
		}
	}
}
int main()
{
	cin>>a>>b;
	n=a.length();m=b.length();
	for(int i=0;i<n;i++)
		x[a[i]-'a'][i]=1;
	for(int i=0;i<m;i++)
		y[b[m-i-1]-'a'][i]=1;
	
	while(N<n+m)N<<=1;
	for(int i=0;i<N;i++)
		if(i&1)rev[i]=(rev[i>>1]>>1)^(N>>1);
		else rev[i]=(rev[i>>1]>>1);
	for(int i=0;i<6;i++)
	{
		ntt(x[i],3);
		ntt(y[i],3);
	}
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
		{
			for(int k=0;k<N;k++)
				r[i*6+j][k]=(ll)x[i][k]*y[j][k]%MOD;
			ntt(r[i*6+j],qmi(3,MOD-2));
		}
	for(int k=m-1;k<=n-1;k++)
	{
		for(int i=0;i<6;i++)fa[i]=i;
		cnt=0;
		for(int i=0;i<6;i++)
			for(int j=0;j<6;j++)
				if(r[i*6+j][k])merge(i,j);
		printf("%d ",cnt);
	}
	printf("\n");
    return 0;
}
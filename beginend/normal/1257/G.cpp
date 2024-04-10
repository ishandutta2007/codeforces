#include<bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long LL;
typedef std::pair<int,int> pi;

const int MOD=998244353;
const int N=200005;

int n,s[3000005],L,rev[N*4],A[N*4],B[N*4];
std::vector<int> wn1[25],wn2[25];
std::priority_queue<pi> que;

void pre(int n)
{
	int lg=0;
	for (L=1;L<=n;L<<=1,lg++);
	for (int i=0;i<L;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
}

int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

void init()
{
	for (int i=0;i<20;i++)
	{
		int w1=ksm(3,(MOD-1)/(1<<(i+1))),w2=ksm(3,MOD-1-(MOD-1)/(1<<(i+1)));
		wn1[i].pb(1);wn2[i].pb(1);
		for (int j=1;j<(1<<i);j++) wn1[i].pb((LL)wn1[i][j-1]*w1%MOD),wn2[i].pb((LL)wn2[i][j-1]*w2%MOD);
	}
}

void NTT(int *a,int f)
{
	for (int i=0;i<L;i++) if (i<rev[i]) std::swap(a[i],a[rev[i]]);
	for (int i=1,lg=0;i<L;i<<=1,lg++)
	{
		for (int j=0;j<L;j+=(i<<1))
			for (int k=0;k<i;k++)
			{
				int u=a[j+k],v=(LL)a[j+k+i]*(f==1?wn1[lg][k]:wn2[lg][k])%MOD;
				a[j+k]=(u+v)%MOD;a[j+k+i]=(u+MOD-v)%MOD;
			}
	}
	if (f==-1) for (int i=0,ny=ksm(L,MOD-2);i<L;i++) a[i]=(LL)a[i]*ny%MOD;
}

struct poly
{
	std::vector<int> c;
	
	poly operator * (const poly &a) const
	{
		int n=c.size(),m=a.c.size();
		pre(n+m);
		for (int i=0;i<L;i++) A[i]=B[i]=0;
		for (int i=0;i<n;i++) A[i]=c[i];
		for (int i=0;i<m;i++) B[i]=a.c[i];
		NTT(A,1);NTT(B,1);
		for (int i=0;i<L;i++) A[i]=(LL)A[i]*B[i]%MOD;
		NTT(A,-1);
		poly ans;
		for (int i=0;i<n+m;i++) ans.c.pb(A[i]);
		return ans;
	}
}p[N];

int main()
{
	init();
	scanf("%d",&n);
	int mx=0,tot=0;
	for (int i=1,x;i<=n;i++) scanf("%d",&x),s[x]++,mx=std::max(mx,x);
	for (int i=2;i<=mx;i++)
		if (s[i])
		{
			tot++;
			for (int j=0;j<=s[i];j++) p[tot].c.pb(1);
			que.push(mp(-s[i]-1,tot));
		}
	while (1)
	{
		int x=que.top().second;que.pop();
		if (que.empty()) {printf("%d\n",p[x].c[(n+1)/2]);return 0;}
		int y=que.top().second;que.pop();
		p[x]=p[x]*p[y];p[y].c.clear();
		que.push(mp(-p[x].c.size(),x));
	}
	return 0;
}
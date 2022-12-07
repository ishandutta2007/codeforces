#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N=500005;
const LL MAX=1e17;
int n,q;
struct qq
{
	int l,r;
	LL k,val;
	qq () {}
	qq (int _l,int _r,int _k)
	{
		l=_l;r=_r;k=_k;
	}
};
LL a[3][N];
LL v[3][N];
bool cmpl (qq x,qq y)	{return x.l<y.l;}
bool cmpr (qq x,qq y)	{return x.r>y.r;}
LL f[N];
void solve (int l,int r,vector<qq> vec)
{
	if (vec.size()==0||l==r) return ;
	int mid=(l+r)>>1;
	vector<qq> L,R,M;
	for (auto x:vec)
	{
		if (x.r<=mid) L.push_back(x);
		else if (x.l>mid) R.push_back(x);
		else M.push_back(x);
	}
	solve(l,mid,L);
	
	int siz=M.size();
	sort(M.begin(),M.end(),cmpl);
	
	LL mn1=MAX,mn2=MAX;
	for (int i=l,j=0;i<=mid;i++)
	{
		while (j<siz&&M[j].l<=i)	{mn1=min(mn1,M[j].k);j++;}
		v[1][i]=min(v[1][i],mn2);
		mn2=min(mn2,mn1+min(v[0][i],v[1][i]));
	}
	mn1=MAX;
	for (int j=siz-1,i=mid;j>=0;j--)
	{
		while (M[j].l<=i)	{mn1=min(mn1,min(v[0][i],v[1][i]));i--;}
		M[j].val=mn1;
	}
	sort(M.begin(),M.end(),cmpr);
	mn1=MAX;mn2=MAX;
	for (int i=r,j=0;i>mid;i--)
	{
		while (j<siz&&M[j].r>=i)	{mn1=min(mn1,M[j].k+M[j].val);mn2=min(mn2,M[j].k);j++;}
		
		v[1][i]=min(v[1][i],mn1);
		f[i]=mn2;
	}
	mn1=MAX;
	for (int i=mid+1;i<=r;i++)
	{
		v[1][i]=min(v[1][i],mn1+f[i]);
		mn1=min(mn1,min(v[0][i],v[1][i]));
	}
	
	solve(mid+1,r,R);
}
int main ()
{
	vector<qq> vec;
	scanf("%d%d",&n,&q);
	for (int u=0;u<=2;u++)
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[u][i]);
		a[u][i]+=a[u][i-1];
	}
	for (int u=1;u<=q;u++)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		vec.push_back(qq(l-1,r,k));
	}
	memset(v,63,sizeof(v));
	for(int u=1;u<=n;u++)
	{
		v[2][u]=  -(a[1][u]+a[2][n]-a[2][u-1]);
		v[0][u-1]=-(a[0][u]-a[1][u-1]);
	}
	solve(0,n,vec);
	LL ans=MAX;
	for (int u=0;u<=n;u++) ans=min(ans,v[1][u]+v[2][u]);
	printf("%lld\n",-ans);
	return 0;
}
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005*10;
//const int MOD=1e9+9;
const int MOD=998244353;
const int G=3;
const int GI=332748118;
int add (int x,int y)   {x=x+y;return x>=MOD?x-MOD:x;}
int mul (int x,int y)   {return (LL)x*y%MOD;}
int dec (int x,int y)   {x=x-y;return x<0?x+MOD:x;}
int Pow (int x,int y)
{
	if (y==1) return x;
	int lalal=Pow(x,y>>1);
	lalal=mul(lalal,lalal);
	if (y&1) lalal=mul(lalal,x);
	return lalal;
}
struct qq
{
	int x,y,last;
}E[N*2];int num,last[N];
void init (int x,int y)
{
	E[++num].x=x;E[num].y=y;
	E[num].last=last[x];
	last[x]=num;
}
int n,k;
int JC[N],inv[N];
int tot[N],fa[N];
vector<int> e[N];
void dfs (int x)
{
	tot[x]=1;
	for (int u=last[x];u!=-1;u=E[u].last)
	{
		int y=E[u].y;
		if (y==fa[x]) continue;
		e[x].push_back(y);fa[y]=x;dfs(y);
		tot[x]=tot[x]+tot[y];
	}
}
void solve (int l,int r)
{
	if (l==r)	return ;
	int mid=(l+r)>>1;
	solve(l,mid);solve(mid+1,r);
}
int A[N],a[N];
int bin[N];
vector<int> vec[N];
void NTT (int *a,int n,int o)
{
	for (int u=0;u<n;u++)	bin[u]=(bin[u>>1]>>1)|((u&1)*(n>>1));
	for (int u=0;u<n;u++)	if (u<bin[u])	swap(a[u],a[bin[u]]);
	for (int u=1;u<n;u<<=1)
	{
		int wn=Pow(o==1?G:GI,(MOD-1)/(u<<1)),w,t;
		for (int i=0;i<n;i=i+(u<<1))
		{
			w=1;
			for (int j=0;j<u;j++)
			{
				t=mul(w,a[u+i+j]);
				a[u+i+j]=dec(a[i+j],t);
				a[i+j]=add(a[i+j],t);
				w=mul(w,wn);
			}
		}
	}
	if (o==-1)
	{
		int inv=Pow(n,MOD-2);
		for (int u=0;u<n;u++) a[u]=mul(a[u],inv);
	}
}
void solve (int *a,int ln,int l,int r)
{
	if (l==r)	{a[0]=1;a[1]=A[l];return ;}
	int mid=(l+r)>>1;
	int g0[ln+10],g1[ln+10];
	memset(g0,0,sizeof(g0));memset(g1,0,sizeof(g1));
	solve(g0,ln>>1,l,mid);solve(g1,ln>>1,mid+1,r);
	NTT(g0,ln,1);NTT(g1,ln,1);
	for (int u=0;u<ln;u++) a[u]=mul(g0[u],g1[u]);
	NTT(a,ln,-1);
	/*printf("%d %d\n",l,r);
	for (int u=0;u<ln;u++) printf("%d ",g0[u]);
	printf("\n");
	for (int u=0;u<ln;u++) printf("%d ",g1[u]);
	printf("\n");
	system("pause");*/
}
int g[N];//
bool cmp (int x,int y)	{return tot[x]<tot[y];}
int calc1 (int x)
{
	int siz=vec[x].size()-1,lalal=0;
	for (int u=0;u<=min(siz,k);u++) lalal=add(lalal,mul(mul(vec[x][u],JC[k]),inv[k-u]));
	return lalal;
}
void  Dec (int x,int xx)
{
	//printf("Dec:%d %d\n",x,xx);
	int siz=vec[x].size()-1;
	for (int u=1;u<=siz;u++)	vec[x][u]=dec(vec[x][u],mul(vec[x][u-1],xx));
}
void Add (int x,int xx)
{
	//printf("Add:%d %d\n",x,xx);
	int siz=vec[x].size()-1;
	for (int u=siz-1;u>=0;u--)	vec[x][u+1]=add(vec[x][u+1],mul(vec[x][u],xx));
}
int ans=0;
void calc (int x)
{
	int siz=e[x].size();
	sort(e[x].begin(),e[x].end(),cmp);
	int lst=-1,t=0;
	for (int u=0;u<siz;u++)
	{
		int y=e[x][u];
		calc(y);
		if (tot[y]!=lst)
		{
			if (lst!=-1) Add(x,lst);
			Dec(x,tot[y]);
			t=calc1(x);
			lst=tot[y];
		}
		//printf("x:%d y:%d %d %d\n",x,y,g[x],g[y]);
		ans=add(ans,mul(g[y],g[x]));
		/*for (int i=0;i<vec[x].size();i++) printf("%d ",vec[x][i]);
		printf("\n");
		printf("t:%d %d\n",t,g[y]);
		system("pause");*/
		ans=add(ans,mul(g[y],t));
		g[x]=add(g[x],g[y]);
	}
	if (lst!=-1)  Add(x,lst);
	/*printf("YES:%d\n",x);
	for (int i=0;i<vec[x].size();i++) printf("%d ",vec[x][i]);
	printf("\n");*/
	
	Dec(x,n-tot[x]);
/*	for (int i=0;i<vec[x].size();i++) printf("%d ",vec[x][i]);
	printf("\n");*/
	t=calc1(x);
	//printf("x:%d t:%d\n",x,t);
	g[x]=add(g[x],t);
}
int main()
{
	//printf("%d\n",Pow(3,MOD-2));
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&k);
	if(k==1)
		return printf("%lld",(1ll*(n-1ll)*n/2ll)%MOD),0;
	JC[0]=1;for (int u=1;u<=k;u++) JC[u]=mul(JC[u-1],u);
	inv[k]=Pow(JC[k],MOD-2);
	for (int u=k;u>=0;u--) inv[u-1]=mul(inv[u],u);
	for (int u=1;u<n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);init(y,x);
	}
	dfs(1);
	for (int u=1;u<=n;u++)
	{
		int nn=0;
		int siz=e[u].size();
		for (int i=0;i<siz;i++)	{nn++;A[nn]=tot[e[u][i]];}
		A[++nn]=n-tot[u];
		int ln=1;while (ln<=2*(nn+1)) ln<<=1;
		/*printf("ln:%d\n",ln);
		for (int u=1;u<=nn;u++) printf("%d ",A[u]);
		printf("\n");*/
		solve(a,ln,1,nn);
		for (int i=0;i<=nn;i++) 
		{
			vec[u].push_back(a[i]);
			//printf("%d ",a[i]);
		}
	//	printf("\n");
	}
	calc(1);
	printf("%d\n",ans);
	return 0;
}
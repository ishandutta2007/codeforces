// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

#define getcode(i,j) (((i)>>(j))&1)
const int maxn=(1<<22)+100;
int f[maxn],a[maxn],id[maxn],fa[maxn],n,m;
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
int un(int x,int y)
{
	if(!x||!y)return x|y;
	f[gf(x)]=gf(y);
	return gf(y);
}

int merge(int msk)
{
	if(fa[msk]!=-1)return fa[msk];
//	printf("merge %d\n",msk);
	int k=id[msk];
	for(int i=0;i<n;i++)if(getcode(msk,i))
		k=un(k,merge(msk^(1<<i)));
	return fa[msk]=k;
}

int main()
{
	memset(fa,-1,sizeof(fa));
	get2(n,m);
	for(int i=1;i<=m;i++)
	{
		get1(a[i]);
		f[i]=id[a[i]]=i;
	}
	for(int i=0;i<(1<<n);i++)
	{
		int cur=id[(1<<n)-1^i];
		if(!cur)continue;
//		printf("i= %d cur= %d\n",i,cur);
		merge(i);
		un(cur,fa[i]);
	}
	int ans=0;
	for(int i=1;i<=m;i++)if(f[i]==i)ans++;
	printendl(ans);
	return 0;
}
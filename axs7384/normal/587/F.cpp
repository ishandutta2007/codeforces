#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int n,l[N];
vector<char> s[N];
char c[N];

//IO
inline void read(int &x)
{
	char c=getchar();
	x=0;
	while (c>'9'||c<'0')
		c=getchar();
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
inline void writeln(ll x)
{
	if (x==0)
	{
		puts("0");
		return;
	}
	int a[20];
	a[0]=0;
	while (x)
	{
		a[++a[0]]=x%10;
		x/=10;
	}
	while (a[0])
		putchar(a[a[0]--]+'0');
	putchar('\n');
}

//block
const int LEN=355;
int st[LEN],ed[LEN],be[N],tot;
ll val[N],block[LEN];
inline void add(int x,int v)
{
	for (int i=be[x]+1;i<=tot;++i)
		block[i]+=v;
	for (int i=x;i<=ed[be[x]];++i)
		val[i]+=v;
}

//ac
int e[N][27],fail[N],q[N],cnt;
vector<int> a[N],v[N];
inline void insert(int x)
{
	int p=1;
	for (int i=1;i<=l[x];++i)
	{
		if (!e[p][s[x][i]-'a'])
			e[p][s[x][i]-'a']=++cnt;
		p=e[p][s[x][i]-'a'];
	}
	v[p].push_back(x);
}
inline void build()
{
	int l=0,r=0;
	for (int i=0;i<26;++i)
		if (e[1][i])
		{
			fail[e[1][i]]=1;
			q[++r]=e[1][i];
		}
		else
			e[1][i]=1;
	while (l<=r)
	{
		int now=q[++l];
		for (int i=0;i<26;i++)
			if (!e[now][i])
				e[now][i]=e[fail[now]][i];
			else 
			{
				q[++r]=e[now][i];
				fail[q[r]]=e[fail[now]][i];
			}
	}
	for (int i=2;i<=cnt;++i)
		a[fail[i]].push_back(i);
}

//ask
int m;
struct data
{
	int l,r,id;
	ll ans;
}f[N];
vector<int> Q[N],g[N];
inline void work(int x)
{
	for (unsigned i=0;i<v[x].size();++i)
		add(v[x][i],1);
	for (unsigned i=0;i<g[x].size();++i)
		f[g[x][i]].ans+=block[be[f[g[x][i]].r]]+val[f[g[x][i]].r]
					-block[be[f[g[x][i]].l]]-val[f[g[x][i]].l];
	for (unsigned i=0;i<a[x].size();++i)
		work(a[x][i]);
	for (unsigned i=0;i<v[x].size();++i)
		add(v[x][i],-1);
}
ll sum[N];
int size[N],tag[N];
inline void work(int x,int y)
{
	size[x]=(tag[x]==y);
	for (unsigned i=0;i<a[x].size();++i)
	{
		work(a[x][i],y);
		size[x]+=size[a[x][i]];
	}
	for (unsigned i=0;i<v[x].size();++i)
		sum[v[x][i]]+=size[x];
}
//hash
/*const int mod1=1e9+7,mod2=1e9+7;
vector<pair<int,int> > has[N];
pair<int,int> Pow[N];
ll sum[N];
inline int ksm(int x,int y,int mod)
{
	int ans=1;
	for (;y;y/=2,x=(ll)x*x%mod)
		if (y&1)
			ans=(ll)ans*x%mod;
	return ans;
}*/

int main()
{
	//freopen("362f.in","r",stdin);
	//inv[0]=
	/*Pow[0]=make_pair(1,1);
	for (int i=1;i<=100000;++i)
		Pow[i]=make_pair((int)((ll)Pow[i-1].first*37%mod1),
						 (int)((ll)Pow[i-1].second*37%mod2));*/
	/*inv[1]=make_pair(ksm(37,mod1-2,mod1),ksm(37,mod2-2,mod2));
	for (int i=2;i<=100000;+=i)
		inv[i]=make_pair((int)((ll)inv[i-1].first*inv[1].first%mod1),
						 (int)((ll)inv[i-1].second*inv[1].second%mod2));*/
	read(n);
	read(m);
	cnt=1;
	for (int i=1;i<=n;++i)
	{
		scanf("%s",c+1);
		l[i]=strlen(c+1);
		s[i].resize(l[i]+2);
		for (int j=1;j<=l[i];++j)
			s[i][j]=c[j];
		insert(i);
		/*has[i].resize(l[i]+1);
		for (int j=1;j<=l[i];++j)
			has[i][j]=make_pair((int)(((ll)has[i][j-1].first*37+s[i][j]-'a'+1)%mod1),
								(int)(((ll)has[i][j-1].second*37+s[i][j]-'a'+1)%mod2));*/
	}
	build();
	for (int i=1;i<=m;++i)
	{
		read(f[i].l);
		--f[i].l;
		read(f[i].r);
		read(f[i].id);
		if (l[f[i].id]>=LEN)
		//if (1)
			Q[f[i].id].push_back(i);
		else
		{
			for (int j=1,p=1;j<=l[f[i].id];++j)
			{
				p=e[p][s[f[i].id][j]-'a'];
				g[p].push_back(i);
			}
		}
	}
	for (int i=1;i<=n;i+=LEN)
	{
		st[++tot]=i;
		ed[tot]=min(n,i+LEN-1);
		for (int j=i;j<=ed[tot];++j)
			be[j]=tot;	
	}
	work(1);
	for (int i=1;i<=n;++i)
		if (Q[i].size())
		{
			/*for (int j=1;j<=n;++j)
			{
				sum[j]=sum[j-1];
				for (int k=l[j];k<=l[i];++k)
					if (has[j][l[j]].first==(has[i][k].first-(ll)has[i][k-l[j]].first*Pow[l[j]].first%mod1+mod1)%mod1&&
					    has[j][l[j]].second==(has[i][k].second-(ll)has[i][k-l[j]].second*Pow[l[j]].second%mod2+mod2)%mod2)
						++sum[j];
			}
			for (unsigned j=0;j<Q[i].size();++j)
				f[Q[i][j]].ans=sum[f[Q[i][j]].r]-sum[f[Q[i][j]].l];*/
			for (int j=0;j<=n;++j)
				sum[j]=0;
			for (int j=1,p=1;j<=l[i];++j)
			{
				p=e[p][s[i][j]-'a'];
				tag[p]=i;
			}
			work(1,i);
			for (int j=1;j<=n;++j)
				sum[j]+=sum[j-1];
			for (unsigned j=0;j<Q[i].size();++j)
				f[Q[i][j]].ans=sum[f[Q[i][j]].r]-sum[f[Q[i][j]].l];
		}
	for (int i=1;i<=m;++i)
		writeln(f[i].ans);
	return 0;
}
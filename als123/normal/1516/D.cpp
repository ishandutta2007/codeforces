#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
typedef long long LL;
const int N=200005;
int a[N];
int n,q;
int gcd (int x,int y)	{return x==0?y:gcd(y%x,x);}
int fa[N][20];
int solve (int l,int r)
{
	int ans=0;
	for (int u=19;u>=0;u--)
	{
		//printf("%d %d %d\n",u,l,fa[l][u]);
		if (fa[l][u]<=r)
		{
			ans=ans+(1<<u);
			l=fa[l][u];
		}
	}
	return ans+1;
}
vector<int> vec[N];
multiset<int> s;
multiset<int> :: iterator it;
int t[N];
void Ins (int x)
{
	int siz=vec[x].size();
	for (int u=0;u<siz;u++)
	{
		int xx=vec[x][u];
		if (t[xx]!=0)
		{
			it=s.find(t[xx]);s.erase(it);
		}
		t[xx]++;
		s.insert(t[xx]);
	}
}
void Del (int x)
{
	int siz=vec[x].size();
	for (int u=0;u<siz;u++)
	{
		int xx=vec[x][u];
		it=s.find(t[xx]);s.erase(it);
		t[xx]--;
		s.insert(t[xx]);
	}
}
bool check ()
{
	if (s.empty()) return true;
	it=--(s.end());
	if ((*it)>1) return false;
	return true;
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	for (int u=1;u<=n;u++)
	{
		for (int i=2;i*i<=a[u];i++) if (a[u]%i==0)
		{
			vec[u].push_back(i);
			while (a[u]%i==0)
			{
		
				a[u]/=i;
			}
		}
		if (a[u]!=1) vec[u].push_back(a[u]);
	}
	int r=n;fa[n][0]=n+1;
	Ins(n);
	for (int u=n-1;u>=1;u--)
	{
		Ins(u);
		while (check()==false) Del(r--);
		fa[u][0]=r+1; 
	}
/*	for (int u=1;u<=n;u++) printf("%d ",fa[u][0]);
	printf("\n");*/
	
	for (int u=0;u<20;u++) fa[n+1][u]=n+1;
	
	for (int u=1;u<20;u++)
	for (int i=1;i<=n;i++)
	fa[i][u]=fa[fa[i][u-1]][u-1];
	while (q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",solve(l,r));
	}
	return 0;
}
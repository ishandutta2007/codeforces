#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>

typedef long long LL;

const int N=200005;

int n,T,S,y[N],pos[N],sz;
std::map<int,int> ma,id;
std::set<int> se[N];
std::set<int>::iterator it;
bool vis[N];

int gcd(int x,int y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

void exgcd(int x,int y,int &a,int &b)
{
	if (!y) {a=1;b=0;return;}
	exgcd(y,x%y,a,b);
	int tmp=a;a=b;b=tmp-(x/y)*b;
}

int main()
{
	scanf("%d%d",&T,&n);
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		if (i>1) y[i]=(y[i-1]+x)%T;
		(S+=x)%=T;
		if (!ma[y[i]]) ma[y[i]]=1,vis[i]=1;
	}
	int a,b,d=gcd(S,T);
	S/=d;T/=d;
	exgcd(S,T,a,b);
	for (int i=1;i<=n;i++)
	{
		int z=y[i]%d;
		if (!id[z]) id[z]=++sz;
		pos[i]=(LL)a*(y[i]-z)/d%T;
		se[id[z]].insert(pos[i]);
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i]) {printf("%d ",0);continue;}
		int z=id[y[i]%d];
		it=se[z].lower_bound(pos[i]);
		it++;
		if (it!=se[z].end()) printf("%d ",(*it)-pos[i]);
		else printf("%d ",(*se[z].begin())+T-pos[i]);
	}
	return 0;
}
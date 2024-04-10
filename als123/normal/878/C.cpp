#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int n,k;
struct qq
{
	int mx[11],mn[11];
	int size;
};
bool operator < (qq x,qq y)
{
	for (int u=1;u<=k;u++)
		if (x.mx[u]>y.mn[u])
			return false;
	return true;
}
set<qq> s;
int read ()
{
	char ch=getchar();int x=0;
	while (ch<'0'||ch>'9')	ch=getchar();
	while (ch>='0'&&ch<='9')	{x=x*10+ch-'0';ch=getchar();}
	return x;
}
int main()
{
	n=read();k=read();
	for (int u=1;u<=n;u++)
	{
		qq x;
		for (int i=1;i<=k;i++)
		{
			x.mn[i]=x.mx[i]=read();
			x.size=1;
		}
		set<qq> :: iterator  l,r;
		l=s.lower_bound(x);
		r=s.upper_bound(x);
		while (l!=r)
		{
			x.size=x.size+(*l).size;
			for (int u=1;u<=k;u++)
			{
				x.mn[u]=min(x.mn[u],(*l).mn[u]);
				x.mx[u]=max(x.mx[u],(*l).mx[u]);
			}
			s.erase(l++);
			//l++;
		}
		s.insert(x);
		printf("%d\n",(*s.rbegin()).size);
	}
	return 0;
}
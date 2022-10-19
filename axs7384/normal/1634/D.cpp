#include<bits/stdc++.h>
using namespace std;
const int N=100;
int a[N],p[N],f[N];
set<int> s;
int t,n;
int lastdel;
int cnt;
bool cmp(int x,int y)
{
	return f[x]<f[y];
}
inline void work()
{
	for (int i=1;i<=4;++i)
	{
		p[i]=i;
		putchar('?');
		for (int j=1;j<=4;++j)
			if (i!=j)
				printf(" %d",a[j]);
		puts("");
		fflush(stdout);
		scanf("%d",&f[i]);
	}
	sort(p+1,p+5,cmp);
	lastdel=a[p[4]];
	// for (int i=1;i<=4;++i)
	// 	cout<<a[p[i]]<<' ';cout<<endl;
	s.erase(a[p[3]]);
	s.erase(a[p[4]]);
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			s.insert(i);
		while (s.size()>=4)
		{
			cnt=0;
			for (int x:s)
			{
				a[++cnt]=x;
				if (cnt==4)
					break;
			}
			work();
		}
		if (s.size()==3)
		{
			s.insert(lastdel);
			cnt=0;
			for (int x:s)
			{
				a[++cnt]=x;
				if (cnt==4)
					break;
			}
			work();
		}
		cnt=0;
		for (int x:s)
			a[++cnt]=x;
		printf("! %d %d\n",a[1],a[2]);
		fflush(stdout);
	}
	return 0;
}
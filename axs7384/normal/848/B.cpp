#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int h,w,n;
struct data
{
	int opt,x,y,v,id;
	bool operator<(const data&a)const
	{
		return v<a.v;
	}
}a[N];
vector<pair<int,int> >S;
struct point
{
	int x,y;
	bool operator<(const point &a)const
	{
		return (x<a.x)||((x==a.x)&&(y>a.y));
	}
}ans[N];
vector<point> T;
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
int main()
{
	// freopen("848b.in","r",stdin);
	read(n);
	read(w);
	read(h);
	for (int i=1;i<=n;++i)
	{
		a[i].id=i;
		read(a[i].opt);
		if (a[i].opt==1)
		{
			read(a[i].x);
			read(a[i].y);
			a[i].y=-a[i].y;
		}
		else
		{
			read(a[i].y);
			read(a[i].x);
			a[i].x=-a[i].x;
		}
		a[i].v=a[i].x+a[i].y;
	}
	sort(a+1,a+1+n);
	int i=1;
	while (i<=n)
	{
		int r=i;
		while (a[r+1].v==a[r].v&&r!=n)
			++r;
		S.clear();
		T.clear();
		for (int j=i;j<=r;++j)
		{
			S.push_back(make_pair(a[j].x,j));
			if (a[j].opt==1)
				T.push_back((point){a[j].x,h});
			else
				T.push_back((point){w,a[j].y});
		}
		sort(S.begin(),S.end());
		sort(T.begin(),T.end());
		for (unsigned j=0;j<S.size();++j)
			ans[a[S[j].second].id]=T[j];
		i=r+1;
	}
	for (int i=1;i<=n;++i)
		cout<<ans[i].x<<' '<<ans[i].y<<'\n';
	return 0;
}
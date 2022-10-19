#include<bits/stdc++.h>
using namespace std;
#define double long double
const double eps=1e-10,inf=1e12;
const int N=100005;
int n;
inline void read(int &x)
{
	char c=getchar();
	x=0;
	int y=1;
	while (c>'9'||c<'0')
	{
		if (c=='-')
			y=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	x*=y;
}
struct point
{
	int x,y;
}a[N];
struct line
{
	double k,b;
};
inline line make_line(point a,point b)
{
	if (a.x==b.x)
		return (line){inf,a.x};
	if (a.y==b.y)
		return (line){0,a.y};
	double k=(double)(b.y-a.y)/(double)(b.x-a.x);
	return (line){k,a.y-a.x*k};
}
inline bool check(line p)
{
	vector<int> v;
	v.clear();
	for (int i=1;i<=n;++i)
		if ((fabs(p.k-inf)>eps&&fabs(a[i].x*p.k+p.b-a[i].y)>eps)
			||(fabs(p.k-inf)<eps&&fabs(p.b-a[i].x)>eps))
			v.push_back(i);
	if (v.size()<=2)
		return true;
	line q=make_line(a[v[0]],a[v[1]]);
	for (unsigned i=2;i<v.size();++i)
		if ((fabs(q.k-inf)>eps&&fabs(a[v[i]].x*q.k+q.b-a[v[i]].y)>eps)
			||(fabs(q.k-inf)<eps&&fabs(q.b-a[v[i]].x)>eps))
			return false;
	return true;
}
int main()
{
	//freopen("961d.in","r",stdin);
	read(n);
	for (int i=1;i<=n;++i)
	{
		read(a[i].x);
		read(a[i].y);
	}
	/*if (check(make_line(a[1],a[2])))
		puts("1");
	if (check(make_line(a[1],a[3])))
		puts("2");
	if (check(make_line(a[3],a[2])))
		puts("3");*/
	if (n<=4||check(make_line(a[1],a[2]))||check(make_line(a[1],a[3]))
		||check(make_line(a[2],a[3])))
		puts("YES");
	else
		puts("NO");
	return 0;
}
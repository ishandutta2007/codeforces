#include<stdio.h>
#include<bits/stdc++.h>
typedef long long ll;
typedef double db;
using std::sort;
using std::min;
using std::max;
using std::swap;
typedef std::pair<int,int> pii;

void rddi(int*x,int _C)
{
	for(int i=1;i<=_C;i++)
	{
		scanf("%d",x+i);
	}
}
void rddl(ll*x,int _C)
{
	for(int i=1;i<=_C;i++)
	{
		scanf("%lld",x+i);
	}
}
void rddd(db*x,int _C)
{
	for(int i=1;i<=_C;i++)
	{
		scanf("%lf",x+i);
	}
}
int n,k;
int a[1<<20],b[1<<20],s[1<<20],c[1<<20];
void clear()
{}
std::vector<int> merge(std::vector<int>a,
const std::vector<int> b)
{
	for(int t:b)a.push_back(t);
	return a;
}
bool test(std::vector<int>x)
{
	printf("? %u ",(unsigned)x.size());
	for(int t:x)printf("%d ",t);
	puts("");
	fflush(stdout);
	char s[5];
	scanf("%s",s);
	return (*s)=='Y';
}
bool test(std::vector<int>x,std::vector<int>y)
{
	printf("? %u ",(unsigned)x.size()+(unsigned)y.size());
	for(int t:x)printf("%d ",t);
	for(int t:y)printf("%d ",t);
	puts("");
	fflush(stdout);
	char s[5];
	scanf("%s",s);
	return (*s)=='Y';
}

void sol(std::vector<int>x)
{
	if(x.size()<=2)
	{
		while(1)
		{
			printf("! %d\n",x.back());
			x.pop_back();
			fflush(stdout);
			char s[4];
			scanf("%s",s);
			if(s[1]==')')exit(0);
		}
	}
	std::vector<int>v[3];
	for(int i=0;i<x.size();i++)
		v[i%3].push_back(x[i]);
	bool x1=test(v[0],v[1]);
	if(!x1)
	{
		bool x3=test(v[0]);
		if(x3)return sol(merge(v[0],v[2]));
		else return sol(merge(v[1],v[2]));
	}
	bool x2=test(v[0],v[1]);
	if(!x2)
	{
		bool x3=test(v[0]);
		if(x3)return sol(merge(v[0],v[2]));
		else return sol(merge(v[1],v[2]));
	}
	else return sol(merge(v[0],v[1]));
}
void exec()
{
	scanf("%d",&n);
	std::vector<int>fil; 
	for(int i=1;i<=n;i++)
		fil.push_back(i);
	sol(fil);
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}
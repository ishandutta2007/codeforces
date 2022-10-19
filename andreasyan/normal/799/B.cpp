#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
const int N=200003;
struct ban
{
	int p,a,b;
};
struct ban1
{
	int i,p;
};
bool operator<(const ban1& a,const ban1& b)
{
	return a.p>b.p;
}

int n,m;
ban a[N];
bool c[N];
int b[N];
priority_queue<ban1> q[4];
ban1 t;
int main()
{
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i].p);
	}
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i].a);
	}
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i].b);
	}
	for(i=0;i<n;++i)
	{
		t.i=i;
		t.p=a[i].p;
		q[a[i].a].push(t);
		q[a[i].b].push(t);
	}
	scanf("%d",&m);
	for(i=0;i<m;++i)
	{
		scanf("%d",&k);
		bool z=false;
		do
		{
			if(q[k].empty())
			{
				printf("-1 ");
				z=true;
				break;
			}
			t=q[k].top();
			q[k].pop();
		}while(c[t.i]);
		if(z)
			continue;
		c[t.i]=true;
		printf("%d ",t.p);
	}
	printf("\n");
//	system("pause");
	return 0;
}
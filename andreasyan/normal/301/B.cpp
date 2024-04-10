#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;
const int N=102;
struct ban
{
	int x,y;
};
struct ban1
{
	int x;
	int b1;
	int k;
};
bool operator<(const ban1 a,const ban1 b)
{
	return a.b1>b.b1;
}

int n,d;
int a[N];
ban b[N];
bool c[N];
int main()
{
	cin>>n>>d;
	for(int i=1;i<n-1;++i)
		cin>>a[i];
	for(int i=0;i<n;++i)
		cin>>b[i].x>>b[i].y;
	/////////////////////////////////////
	ban1 t;
	priority_queue<ban1> q;
	t.k=0;
	t.x=0;
	t.b1=0;
	q.push(t);
	while(1)
	{
		do
		{
			t=q.top();
			q.pop();
		}while(c[t.x]);
		c[t.x]=true;
		if(t.x==n-1)
		{
			cout<<t.b1<<endl;
//			system("pause");
			return 0;
		}
		for(int i=1;i<n;++i)
		{
			int her=(abs(b[t.x].x-b[i].x)+abs(b[t.x].y-b[i].y))*d;
			ban1 h;
			h.x=i;
			if(t.k>=her)
			{
				h.k=t.k-her;
				h.b1=t.b1;
				h.k+=a[h.x];
			}
			else
			{
				h.k=0;
				her-=t.k;
				h.b1=t.b1+her;
				h.k+=a[h.x];
			}
			if(!c[h.x])
				q.push(h);
		}
	}
	return 0;
}
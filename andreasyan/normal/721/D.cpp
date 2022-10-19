#include <iostream>
#include <queue>
#include <cmath> 
#include <algorithm>
using namespace std;
struct ban
{
	long long num,x;
};
bool operator<(const ban &a,const ban &b)
{
	return a.x>b.x;
}
long long n,m,k,a[200003],minu,mini;
priority_queue<ban> pq;
int main()
{
	long long i,j,x=0,z=0;
	ban c;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<0)
			x^=1;
		c.num=i;
		c.x=abs(a[i]);
		pq.push(c);
	}
	for(j=0;j<m;j++)
	{
		c=pq.top();
		i=c.num;
		pq.pop();
		if(a[i]<0)
			x^=1;
		if(x)
			a[i]+=k;
		else
			a[i]-=k;
		if(a[i]<0)
			x^=1;
		c.x=abs(a[i]);
		pq.push(c);
	}
	for(i=1;i<=n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}
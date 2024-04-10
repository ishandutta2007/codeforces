#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=100005;
int s;
struct ban
{
	int l,r,i;
};
bool operator<(const ban& a,const ban& b)
{
	if((a.l/s)<(b.l/s))
		return true;
	if((a.l/s)>(b.l/s))
		return false;
	return a.r<b.r;
}

int n, m, yans;
int a[N], ans[N];
ban q[N];
int mp[N];
void av(int x)
{
	if(x>n)
		return;
	if(mp[x]==x)
		--yans;
	mp[x]++;
	if(mp[x]==x)
		++yans;
}
void re(int x)
{
	if(x>n)
		return;
	if(mp[x]==x)
		--yans;
	mp[x]--;
	if(mp[x]==x)
		++yans;
}
int main()
{
	/////in
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=0;i<m;++i)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].i=i;
	}
	/////
	s=sqrt(n+0.0);
	sort(q,q+m);
	int l=1;
	int r=0;
	for(int i=0;i<m;++i)
	{
/*		if(i==0 || (q[i-1].l/s)!=(q[i].l/s))
		{
			l=q[i].l;
			r=q[i].l-1;
			yans=0;
			mp.clear();
		}*/
		int ll=q[i].l;
		int rr=q[i].r;
		while(l>ll)
		{
			--l;
			av(a[l]);
		}
		while(r<rr)
		{
			++r;
			av(a[r]);
		}
		while(l<ll)
		{
			re(a[l]);
			++l;
		}
		while(r>rr)
		{
			re(a[r]);
			--r;
		}
		ans[q[i].i]=yans;
	}
	/////out
	for(int i=0;i<m;++i)
	{
		printf("%d\n",ans[i]);
	}
//	system("pause");
	return 0;
}
#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 200005, M = 1000006;
int s;
struct ban
{
	int l, r, i;
};
bool operator<(const ban& a,const ban& b)
{
	if((a.l/s)<(b.l/s))
		return true;
	if((a.l/s)>(b.l/s))
		return false;
    if ((a.l / s) % 2 == 0)
        return a.r<b.r;
    else
        return a.r > b.r;
}

int n, m;
int a[N];
long long ans[N], yans;
ban q[N];
long long mp[M];
void av(int x)
{
	yans-=(mp[x]*mp[x]*x);
	mp[x]++;
	yans+=(mp[x]*mp[x]*x);
}
void re(int x)
{
	yans-=(mp[x]*mp[x]*x);
	mp[x]--;
	yans+=(mp[x]*mp[x]*x);
}
int main()
{
	/////in
	scanf("%d%d", &n, &m);
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
		printf("%I64d\n",ans[i]);
	}
//	system("pause");
	return 0;
}
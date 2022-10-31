#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=500005;
int m,n,k,T,a[200005],p,top,i;
struct str{
	int l,r,d;
}b[200005],t[200005],sta[200005];
bool cmp(str a,str b)
{
	return a.r<b.r;
}
bool check(int d)
{
	p=0;
	for(i=1;i<=k;++i)
		if(b[i].d>d)
			t[++p]=b[i];
	sort(t+1,t+1+p,cmp);
	long long ans=n+1;
	top=0;
	for(i=1;i<=p;++i)
	{
		str tmp=t[i];
		while(top>0&&sta[top].r>=tmp.l)
		{
			tmp.l=min(tmp.l,sta[top].l);
			--top;
		}
		sta[++top]=tmp;
	}
	for(i=1;i<=top;++i)
		ans+=(sta[i].r-sta[i].l)*2;
	return (ans<=T);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d %d %d",&m,&n,&k,&T);
	for(i=1;i<=m;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+m);
	for(i=1;i<=k;++i)
	{
		scanf("%d %d %d",&b[i].l,&b[i].r,&b[i].d);
		--b[i].l;
	}
	int l,r;
	l=1;
	r=m+1;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(a[mid]))
			r=mid;
		else
			l=mid+1;
	}
	cout<<m-l+1;
}
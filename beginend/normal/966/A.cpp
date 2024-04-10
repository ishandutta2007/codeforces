#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;
const int inf=2000000000;

int n,m,s1,s2,v,a[N],b[N];

int query(int x1,int y1,int x2,int y2)
{
	if (x1==x2) return abs(y1-y2);
	int p=lower_bound(a+1,a+s1+1,y1)-a,ans=inf;
	if (p<=s1) ans=min(ans,abs(a[p]-y1)+abs(x1-x2)+abs(a[p]-y2));
	p--;
	if (p>0) ans=min(ans,abs(a[p]-y1)+abs(x1-x2)+abs(a[p]-y2));
	p=lower_bound(b+1,b+s2+1,y1)-b;
	if (p<=s2) ans=min(ans,abs(b[p]-y1)+(abs(x1-x2)+v-1)/v+abs(b[p]-y2));
	p--;
	if (p>0) ans=min(ans,abs(b[p]-y1)+(abs(x1-x2)+v-1)/v+abs(b[p]-y2));
	return ans;
}

int main()
{
	scanf("%d%d%d%d%d",&n,&m,&s1,&s2,&v);
	for (int i=1;i<=s1;i++) scanf("%d",&a[i]);
	for (int i=1;i<=s2;i++) scanf("%d",&b[i]);
	int q;scanf("%d",&q);
	while (q--)
	{
		int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%d\n",query(x1,y1,x2,y2));
	}
	return 0;
}
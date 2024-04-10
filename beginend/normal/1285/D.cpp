#include<bits/stdc++.h>

const int N=100005;

int n,bin[35],rt,sz;
struct tree{int l,r;}t[N*35];

void ins(int &d,int x,int w)
{
	if (!d) d=++sz;
	if (x<0) return;
	if (w&bin[x]) ins(t[d].r,x-1,w);
	else ins(t[d].l,x-1,w);
}

int query(int d,int x)
{
	if (x<0) return 0;
	if (!t[d].l) return query(t[d].r,x-1);
	else if (!t[d].r) return query(t[d].l,x-1);
	else return std::min(query(t[d].l,x-1),query(t[d].r,x-1))+bin[x];
}

int main()
{
	bin[0]=1;
	for (int i=1;i<=30;i++) bin[i]=bin[i-1]*2;
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++) scanf("%d",&x),ins(rt,30,x);
	printf("%d\n",query(rt,30));
	return 0;
}
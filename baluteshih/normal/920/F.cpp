#pragma GCC optimize ("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
using namespace std;

int answer[1050001],Ends[1050000];
long long seg[1050000];

void modify(int L,int R,int l,int r,int rt)
{
	if(Ends[rt]) return;
	int m=(l+r)>>1;
	if(L<=l && R>=r)
	{
		if(l==r)
		{
			seg[rt]=answer[seg[rt]];
			if(seg[rt]==2) Ends[rt]=1;
			return ;
		}
		if(!Ends[rt<<1]) modify(L,R,l,m,rt<<1);
		if(!Ends[rt<<1|1]) modify(L,R,m+1,r,rt<<1|1);
		seg[rt]=seg[rt<<1]+seg[rt<<1|1];
		Ends[rt]=Ends[rt<<1]&Ends[rt<<1|1];
		return;
	}
	if(L<=m && !Ends[rt<<1]) modify(L,R,l,m,rt<<1);
	if(R>m && !Ends[rt<<1|1]) modify(L,R,m+1,r,rt<<1|1);
	seg[rt]=seg[rt<<1]+seg[rt<<1|1];
	Ends[rt]=Ends[rt<<1]&Ends[rt<<1|1];
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%d",&seg[rt]);
		if(seg[rt]==1 || seg[rt]==2) Ends[rt]=1;
		return;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1),build(m+1,r,rt<<1|1);
	seg[rt]=seg[rt<<1]+seg[rt<<1|1];
	Ends[rt]=Ends[rt<<1]&Ends[rt<<1|1];
}

long long query(int L,int R,int l,int r,int rt)
{
	if(L<=l && R>=r) return seg[rt];
	int m=(l+r)>>1;
	long long re=0;
	if(L<=m) re=query(L,R,l,m,rt<<1);
	if(R>m) re+=query(L,R,m+1,r,rt<<1|1);
	return re;
}

int main()
{
	int n,m,l,r,k;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=1000000;i++)
		for(int j=i;j<=1000000;j+=i) answer[j]++;
	build(1,n,1);
	while(m--)
	{
		scanf("%d%d%d",&k,&l,&r);
		if(k==1)
			modify(l,r,1,n,1);
		else
			printf("%lld\n",query(l,r,1,n,1));
	}
}